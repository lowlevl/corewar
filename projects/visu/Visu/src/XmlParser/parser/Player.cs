using System;
using System.Xml;
using System.Text;

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

        public override string ToString()
        {
            return '{' + string.Format(".Id: {0}, .Name: {1}", Id, Name) + '}';
        }
    }

    public partial class Parser
    {
        public delegate void NewPlayerHandler(object source, PlayerEventArgs args);
        public event NewPlayerHandler NewPlayer = null;

        public void ReadPlayerXml(XmlReader reader) {
            int id = 0, size = 0;
            byte[] buffer = null;
            string name = "";

            while (reader.Read()) {
                if (reader.NodeType == XmlNodeType.Element) {
                    switch (reader.Name) {
                        case "id":
                            id = reader.ReadElementContentAsInt();
                            break;
                        case "size":
                            size = reader.ReadElementContentAsInt();
                            break;
                        case "name":
                            buffer = new byte[size];
                            int s = reader.ReadElementContentAsBase64(buffer, 0, size);
                            name = Encoding.ASCII.GetString(buffer, 0, s);
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
