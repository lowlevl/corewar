using System;
using System.Xml;

namespace XmlParser
{
    public partial class Parser
    {
        public delegate void EndEventHandler(object source);
        public event EndEventHandler EndEvent = null;

        public void ReadEndXml(XmlReader reader) {
            reader.Close();
            OnEndEvent();
        }

        protected virtual void OnEndEvent() {
            EndEventHandler handler = EndEvent;

            if (handler != null) {
                handler(this);
            }
        }
    }
}
