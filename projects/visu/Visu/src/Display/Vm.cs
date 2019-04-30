using System;
using System.Text;
using System.Collections.Generic;
using XmlParser;

namespace Display
{
    public class Processus
    {
        public int Id;
        public int PlayerId;
        public int Pos;
        public Processus(int id, int playerId, int pos)
        {
            Id = id;
            PlayerId = playerId;
            Pos = pos;
        }
    }

    public class Dump
    {
        public delegate void OnChangeHandler(object source, int at, int len);
        public event OnChangeHandler ChangeEvent = null;
        public delegate void OnNewProcessus(object source, ref Processus proc);
        public event OnNewProcessus NewProcEvent = null;

        byte[] dump = null;
        byte[] heatMap = null;
        int dumpSize = 0;
        public readonly Dictionary<int, Processus> ProcessusList = new Dictionary<int, Processus>();

        public byte[] Memory
        {
            get { return dump; }
        }

        public int MemorySize
        {
            get { return dumpSize; }
        }

        public byte[] MapOwner
        {
            get { return heatMap; }
        }

        public Dump() { }

        public Dump(int size)
        {
            InitDump(size);
        }

        public void InitDump(int size)
        {
            dump = new byte[size];
            heatMap = new byte[size];
            dumpSize = size;
        }

        public byte getOwner(int at)
        {
            return heatMap[at];
        }

        public void SetMemChunk(int at, byte[] chunk)
        {
            int len = chunk.Length;
            if (dump == null)
                InitDump(len);
            if (at + len > dumpSize)
            {
                int overflow = dumpSize - at;

                Array.Copy(chunk, 0, dump, at, overflow);
                Array.Copy(chunk, overflow, dump, 0, len - overflow);
            }
            else
            {
                chunk.CopyTo(dump, at);
            }
            DumpMem();
            OnChange(at, len);
        }

        public void SetOwnerZone(int at, int len, byte owner)
        {
            if (at + len > dumpSize)
            {
                int overflow = dumpSize - at;
                int i = at;
                for (; i < dumpSize; i++)
                {
                    heatMap[i] = owner;
                }
                for (int j = 0; i + j < len; j++)
                {
                    heatMap[j] = owner;
                }
            }
            else
            {
                for (int i = 0; i < len; i++)
                {
                    heatMap[i + at] = owner;
                }
            }
        }

        public void SetOwnerZone(int at, byte[] heatMap)
        {
            if (heatMap == null)
                InitDump(heatMap.Length);
            heatMap.CopyTo(this.heatMap, at);
            // DumpHeatMap();
            OnChange(at, heatMap.Length);
        }

        public void DumpHeatMap()
        {
            StringBuilder stringBuilder = new StringBuilder(string.Format("Heat Map {0}:\n", dumpSize));
            for (int i = 0; i < dumpSize; i++)
            {
                stringBuilder.AppendFormat("{0} ", heatMap[i]);
            }
            Logger.Log.WriteLine(stringBuilder.ToString());
        }

        public void DumpMem()
        {
            StringBuilder stringBuilder = new StringBuilder(string.Format("Dump {0}:\n", dumpSize));
            for (int i = 0; i < dumpSize; i++)
            {
                stringBuilder.AppendFormat("{0} ", dump[i]);
            }
            Logger.Log.WriteLine(stringBuilder.ToString());
        }

        protected virtual void OnChange(int at, int len)
        {
            ChangeEvent?.Invoke(this, at, len);
        }

        public void OnMemChunkChange(object _source, MemChunkEventArgs e) => SetMemChunk(e.Idx, e.Chunk);
        public void OnMapChunkUpdate(object _source, MapChunkEventArgs e) => SetOwnerZone(e.Idx, e.Chunk);

        protected virtual void OnNewProc(ref Processus proc) => NewProcEvent?.Invoke(this, ref proc);
        public void OnProcUpdate(object _source, ProcEventArgs e)
        {
            Processus proc;

            if (ProcessusList.TryGetValue(e.Id, out proc))
            {
                proc.Pos = e.Pos;
            }
            else
            {
                proc = new Processus(e.Id, e.PlayerId, e.Pos);
                ProcessusList.Add(e.Id, proc);
                OnNewProc(ref proc);
            }
            Logger.Log.WriteLine("proc id({0}) pos({1})", e.Id, e.Pos);
        }
    }
}
