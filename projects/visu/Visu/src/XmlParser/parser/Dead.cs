using System;
using System.Xml;

namespace XmlParser
{
    public class DeadProcEventArgs : EventArgs
    {
        public readonly int Id;
        public readonly int PlayerId;

        public DeadProcEventArgs(int id, int playerId)
        {
            Id = id;
            PlayerId = playerId;
        }
    }

    public partial class Parser
    {
        public delegate void DeadProcHandler(object source, DeadProcEventArgs args);
        public event DeadProcHandler DeadProcEvent = null;

        public void ReadDeadXml(XmlReader reader)
        {
            int id = 0, playerId = 0;

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
                    }
                }
            }
            OnDeadProc(new DeadProcEventArgs(id, playerId));
        }

        protected virtual void OnDeadProc(DeadProcEventArgs args) => DeadProcEvent?.Invoke(this, args);
    }
}
