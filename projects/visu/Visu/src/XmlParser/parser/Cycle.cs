using System;
using System.Xml;

namespace XmlParser
{
    public class CycleUpdateEventArgs : EventArgs
    {
        public readonly int CurrentCycle;
        public readonly int NextCheckCycle;
        public readonly int NbLive;
        public readonly int NbCheck;
        public readonly int CycleToDie;

        public CycleUpdateEventArgs(int currentCycle, int nextCheckCycle, int nbLive, int nbCheck, int cycleToDie)
        {
            CurrentCycle = currentCycle;
            NextCheckCycle = nextCheckCycle;
            NbLive = nbLive;
            NbCheck = nbCheck;
            CycleToDie = cycleToDie;
        }

        public override string ToString()
        {
            return '{' + string.Format(
                ".CurrentCycle: {0}, .NextCheckCycle: {1}, .NbLive: {2}, .NbCheck: {3}, .CycleToDie: {4}",
                CurrentCycle, NextCheckCycle, NbLive, NbCheck, CycleToDie
                ) + '}';
        }
    }

    public partial class Parser
    {
        public delegate void CycleUpdateHandler(object source, CycleUpdateEventArgs args);
        public event CycleUpdateHandler CycleUpdate = null;

        public void ReadCycleXml(XmlReader reader)
        {
            int current = 0, check = 0, live = 0, ncheck = 0, toDie = 0;

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
                        case "ncheck":
                            ncheck = reader.ReadElementContentAsInt();
                            break;
                        case "die":
                            toDie = reader.ReadElementContentAsInt();
                            break;
                        case "live":
                            live = reader.ReadElementContentAsInt();
                            break;
                    }
                }
            }
            reader.Close();
            OnCycleUpdate(new CycleUpdateEventArgs(current, check, live, ncheck, toDie));
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
