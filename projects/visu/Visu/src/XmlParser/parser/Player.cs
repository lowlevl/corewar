using System;
using System.Xml;

namespace XmlParser
{
    public class PlayerEventArgs : EventArgs
    {
        public readonly int Id;
        public readonly string Name;

        public PlayerEventArgs(int id, string name) {
            this.Id = id;
            this.Name = name;
        }
    }

    public partial class Parser
    {
        public delegate void NewPlayerHandler(object source, PlayerEventArgs args);
        public event NewPlayerHandler NewPlayer = null;

        public void ReadPlayerXml(XmlReader reader) {
            int id = 0;
            string name = "";

            while (reader.Read()) {
                if (reader.NodeType == XmlNodeType.Element) {
                    switch (reader.Name) {
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
            OnNewPlayer(new PlayerEventArgs(id, name));
        }

        protected virtual void OnNewPlayer(PlayerEventArgs args) {
            NewPlayerHandler handler = NewPlayer;

            if (handler != null) {
                handler(this, args);
            }
        }
    }
}
