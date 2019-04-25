using System;
using System.Xml;

namespace XmlParser
{
    public class WinnerResultEventArgs : EventArgs
    {
        public readonly int Id;
        public readonly string Name;
        public readonly bool HaveWinner;

        public WinnerResultEventArgs(int id, string name, bool haveWinner) {
            this.Id = id;
            this.Name = name;
            this.HaveWinner = haveWinner;
        }
    }

    public partial class Parser
    {
        public delegate void WinnerResultHandler(object source, WinnerResultEventArgs args);
        public event WinnerResultHandler WinnerResult = null;

        public void ReadWinnerXml(XmlReader reader) {
            int id = 0;
            string name = "";
            bool haveWinner = true;

            while (reader.Read()) {
                if (reader.NodeType == XmlNodeType.Element) {
                    switch (reader.Name) {
                        case "winner":
                            haveWinner = reader.GetAttribute("noWinner") == "false";
                            break;
                        case "id":
                            id = reader.ReadElementContentAsInt();
                            break;
                        case "name":
                            name = reader.ReadElementContentAsString();
                            break;
                    }
                }
            }
            reader.Close();
            OnWinnerResult(new WinnerResultEventArgs(id, name, haveWinner));
        }

        protected virtual void OnWinnerResult(WinnerResultEventArgs args) {
            WinnerResultHandler handler = WinnerResult;

            if (handler != null) {
                handler(this, args);
            }
        }
    }
}
