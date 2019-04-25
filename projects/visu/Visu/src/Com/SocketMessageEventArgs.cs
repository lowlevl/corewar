using System;
using System.Text;

namespace Com
{
    public class SocketMessageEventArgs : EventArgs
    {
        public string message { get; }
        public byte[] raw { get; }

        public SocketMessageEventArgs(byte[] rawMessage)
        {
            raw = rawMessage;
            message = Encoding.ASCII.GetString(raw, 0, raw.Length);
        }
    }
}
