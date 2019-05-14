using System;
using System.Xml;

namespace XmlParser
{
    public class ProcEventArgs : EventArgs
    {
        public readonly int Id;
        public readonly int PlayerId;
        public readonly int Pos;

        public ProcEventArgs(int id, int playerId, int pos)
        {
            this.Id = id;
            this.PlayerId = playerId;
            this.Pos = pos;
        }
    }

    public partial class Parser
    {
        public delegate void ProcUpdateHandler(object source, ProcEventArgs args);
        public event ProcUpdateHandler ProcUpdate = null;

        public void ReadProcXml(XmlReader reader)
        {
            int id = 0, playerId = 0, pos = 0;

            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element)
                {
                    switch (reader.Name)
                    {
                        case "id":
                            id = reader.ReadElementContentAsInt();
                            break;
                        case "playerId":
                            playerId = reader.ReadElementContentAsInt();
                            break;
                        case "pos":
                            pos = reader.ReadElementContentAsInt();
                            break;
                    }
                }
            }
            reader.Close();
            OnProcUpdate(new ProcEventArgs(id, playerId, pos));
        }

        protected virtual void OnProcUpdate(ProcEventArgs args)
        {
            ProcUpdateHandler handler = ProcUpdate;

            if (handler != null)
            {
                handler(this, args);
            }
        }
    }
}
