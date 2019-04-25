using System;
using System.Xml;
using System.IO;
using Com;

namespace XmlParser
{
    public partial class Parser
    {
        public XmlReaderSettings settings;
        public Parser()
        {
            settings = new XmlReaderSettings();
        }

        public Parser(XmlReaderSettings settings)
        {
            this.settings = settings;
        }

        public void OnSocketMessage(object source, SocketMessageEventArgs e)
        {
            using (Stream streamXml = new MemoryStream(e.raw))
            {
                XmlReader reader = XmlReader.Create(streamXml, settings);

                try
                {
                    reader.Read();
                    if (reader.NodeType == XmlNodeType.Element)
                    {
                        switch (reader.Name) {
                            case "mem":
                                ReadMemXml(reader.ReadSubtree());
                                break;
                            case "map":
                                ReadMapXml(reader.ReadSubtree());
                                break;
                            case "player":
                                ReadPlayerXml(reader.ReadSubtree());
                                break;
                            case "proc":
                                ReadProcXml(reader.ReadSubtree());
                                break;
                            case "winner":
                                ReadWinnerXml(reader.ReadSubtree());
                                break;
                            case "aff":
                                ReadAffXml(reader.ReadSubtree());
                                break;
                            case "live":
                                ReadLiveXml(reader.ReadSubtree());
                                break;
                            case "cycle":
                                ReadCycleXml(reader.ReadSubtree());
                                break;
                            case "end":
                                ReadEndXml(reader.ReadSubtree());
                                break;
                            case "dead":
                                ReadDeadXml(reader.ReadSubtree());
                                break;
                            default:
                                Logger.Log.WriteLine("unknow element {0}", e.message);
                                break;
                        }
                    }
                }
                catch (XmlException xe)
                {
                    Logger.Log.WriteLine("{0}({1})", e.message, e.message.Substring(xe.LinePosition, e.message.Length - xe.LinePosition));
                    throw new Exception(xe.Message);
                }
                reader.Close();
            }
        }
    }
}
