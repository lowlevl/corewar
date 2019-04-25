using System;
using System.Xml;

namespace XmlParser
{
    public class CycleUpdateEventArgs : EventArgs
    {
        public readonly int CurrentCycle;
        public readonly int NextCheckCycle;
        public readonly int NbLive;

        public CycleUpdateEventArgs(int current, int check, int nbLive)
        {
            this.NextCheckCycle = check;
            this.CurrentCycle = current;
            this.NbLive = nbLive;
        }
    }

    public partial class Parser
    {
        public delegate void CycleUpdateHandler(object source, CycleUpdateEventArgs args);
        public event CycleUpdateHandler CycleUpdate = null;

        public void ReadCycleXml(XmlReader reader)
        {
            int current = 0, check = 0, live = 0;

            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element)
                {
                    switch (reader.Name)
                    {
                        case "current":
                            current = reader.ReadElementContentAsInt();
                            break;
                        case "check":
                            check = reader.ReadElementContentAsInt();
                            break;
                        case "live":
                            live = reader.ReadElementContentAsInt();
                            break;
                    }
                }
            }
            reader.Close();
            OnCycleUpdate(new CycleUpdateEventArgs(current, check, live));
        }

        protected virtual void OnCycleUpdate(CycleUpdateEventArgs args)
        {
            CycleUpdateHandler handler = CycleUpdate;

            if (handler != null)
            {
                handler(this, args);
            }
        }
    }
}
