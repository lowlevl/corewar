using System;
using System.Xml;

namespace XmlParser
{

    public class MemChunkEventArgs : EventArgs
    {
        public readonly int Idx;
        public readonly int Size;
        public readonly byte[] Chunk;

        public MemChunkEventArgs(int idx, int size, byte[] chunk)
        {
            this.Idx = idx;
            this.Size = size;
            this.Chunk = chunk;
        }
    }

    public partial class Parser
    {
        public delegate void MemChunkUpdateHandler(object source, MemChunkEventArgs args);
        public event MemChunkUpdateHandler MemChunkUpdate = null;

        public void ReadMemXml(XmlReader reader)
        {
            int idx = 0, size = 0;
            byte[] mem = null;

            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element)
                {
                    switch (reader.Name)
                    {
                        case "idx":
                            idx = reader.ReadElementContentAsInt();
                            break;
                        case "size":
                            size = reader.ReadElementContentAsInt();
                            break;
                        case "bytes":
                            if (size == 0)
                            {
                                size = 4096;
                            }
                            mem = new byte[size];
                            reader.ReadElementContentAsBase64(mem, 0, size);
                            break;
                    }
                }
            }
            reader.Close();
            OnMemChunkUpdate(new MemChunkEventArgs(idx, size, mem));
        }

        protected virtual void OnMemChunkUpdate(MemChunkEventArgs args)
        {
            MemChunkUpdateHandler handler = MemChunkUpdate;

            if (handler != null)
            {
                handler(this, args);
            }
        }
    }
}
