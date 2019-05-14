using System;
using System.Xml;

namespace XmlParser
{
    public class AffEventArgs : EventArgs
    {
        public readonly int PlayerId;
        public readonly string Message;
        public AffEventArgs(int playerId, string msg)
        {
            this.PlayerId = playerId;
            this.Message = msg;
        }
    }

    public partial class Parser
    {
        public delegate void AffEventHandler(object source, AffEventArgs args);
        public event AffEventHandler AffEvent = null;

        public void ReadAffXml(XmlReader reader)
        {
            int playerId = 0;
            string msg = "";

            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element)
                {
                    switch (reader.Name)
                    {
                        case "playerId":
                            playerId = reader.ReadElementContentAsInt();
                            break;
                        case "msg":
                            msg = reader.ReadElementContentAsString();
                            break;
                    }
                }
            }
            reader.Close();
            OnAffEvent(new AffEventArgs(playerId, msg));
        }

        protected virtual void OnAffEvent(AffEventArgs args)
        {
            AffEventHandler handler = AffEvent;

            if (handler != null)
            {
                handler(this, args);
            }
        }

    }
}
