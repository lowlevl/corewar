using System;
using System.Xml;

namespace XmlParser
{

    public class MapChunkEventArgs : EventArgs
    {
        public readonly int Idx;
        public readonly int Size;
        public readonly byte[] Chunk;

        public MapChunkEventArgs(int idx, int size, byte[] chunk) {
            this.Idx = idx;
            this.Size = size;
            this.Chunk = chunk;
        }
    }

    public partial class Parser
    {
        public delegate void MapChunkUpdateHandler(object source, MapChunkEventArgs args);
        public event MapChunkUpdateHandler MapChunkUpdate = null;

        public void ReadMapXml(XmlReader reader) {
            int idx = 0, size = 0;
            byte[] map = null;

            while (reader.Read()) {
                if (reader.NodeType == XmlNodeType.Element) {
                    switch (reader.Name) {
                        case "idx":
                            idx = reader.ReadElementContentAsInt();
                            break;
                        case "size":
                            size = reader.ReadElementContentAsInt();
                            break;
                        case "heat":
                            if (size == 0)
                                size = 4096;
                            map = new byte[size];
                            reader.ReadElementContentAsBase64(map, 0, size);
                            break;
                    }
                }
            }
            reader.Close();
            OnMapChunkUpdate(new MapChunkEventArgs(idx, size, map));
        }

        protected virtual void OnMapChunkUpdate(MapChunkEventArgs args) {
            MapChunkUpdateHandler handler = MapChunkUpdate;

            if (handler != null) {
                handler(this, args);
            }
        }
    }
}
