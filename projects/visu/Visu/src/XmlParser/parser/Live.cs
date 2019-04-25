using System;
using System.Xml;

namespace XmlParser
{
    public class LiveEventArgs : EventArgs
    {
        public readonly int PlayerId;

        public LiveEventArgs(int playerId) {
            this.PlayerId = playerId;
        }
    }

    public partial class Parser
    {
        public delegate void LiveEventHandler(object source, LiveEventArgs args);
        public event LiveEventHandler LiveEvent = null;

        public void ReadLiveXml(XmlReader reader) {
            int playerId = 0;

            reader.Read();
            if (reader.NodeType == XmlNodeType.Element && reader.Name == "live") {
                playerId = reader.ReadElementContentAsInt();
            }
            reader.Close();
            OnLiveEvent(new LiveEventArgs(playerId));
        }

        protected virtual void OnLiveEvent(LiveEventArgs args) {
            LiveEventHandler handler = LiveEvent;

            if (handler != null) {
                handler(this, args);
            }
        }
    }
}
