using System;
using System.Threading;
using System.Text;
using System.Collections;
using System.Net;
using System.Net.Sockets;

namespace Com
{
    public class SocketHandler
    {
        static bool SOCKET_SYNC = true;
        public bool gotError = false;
        public bool isClose = true;
        readonly Socket server;
        ArrayList serverList = new ArrayList();
        public delegate void SocketMessageHandler(object source, SocketMessageEventArgs args);
        public event SocketMessageHandler SocketMessage = null;

        readonly byte[] basicReply = Encoding.ASCII.GetBytes("ok");
        readonly byte[] endReply = Encoding.ASCII.GetBytes("ed");
        readonly byte[] endMessage = Encoding.ASCII.GetBytes("<end />");

        public SocketHandler(string ip, int port)
        {
            server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            try
            {
                server.Connect(ip, port);
            }
            catch (SocketException se)
            {
                if (!server.Connected)
                    Console.Error.WriteLine("Unable to connect to server");
                else
                    Console.Error.WriteLine("SocketException: {0}", se.Message);
                gotError = true;
            }
            catch (Exception e)
            {
                Console.Error.WriteLine("socket got exception: {0}", e);
                gotError = true;
            }

            if (!gotError)
            {
                isClose = false;
                serverList.Add(server);
            }
        }

        public Thread SetupListen() => new Thread(ListenForMessageThread);

        void ListenForMessageThread(object data) => ListenForMessage((int)data);
        public void ListenForMessage(int milliTimeout)
        {
            while (!isClose)
            {
                if (server.Poll(milliTimeout, SelectMode.SelectRead))
                {
                    ReadMessage();
                }
            }
        }

        private void ReadMessage()
        {
            byte[] header = new byte[4];
            int byteRec = server.Receive(header);
            int msgLength = BitConverter.ToInt32(header, 0) - 4;
            if (msgLength <= 0)
                return;
            byte[] message = new byte[msgLength];

            byteRec = server.Receive(message);
            if (msgLength > byteRec)
                throw new Exception(
                    String.Format("message not complete, missing {0} bytes", msgLength - byteRec)
                );
            if (message == endReply)
                CloseServer();
            else if (SOCKET_SYNC)
                server.Send(basicReply);
            OnSocketMessage(new SocketMessageEventArgs(message));
        }

        public void CloseServer()
        {
            if (isClose)
                return;
            isClose = true;
            server.Send(endReply);
            server.Close();
        }

        protected virtual void OnSocketMessage(SocketMessageEventArgs e) =>
            SocketMessage?.Invoke(this, e);
    }
}
