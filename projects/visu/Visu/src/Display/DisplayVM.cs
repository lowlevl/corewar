using System;
using System.Collections.Generic;
using Ncurse;
using XmlParser;

namespace Display
{
    public class DisplayVM
    {

        static int bytePerLine = 64;
        static int byteLen = 3;
        static int[] styles = new int[] {
            0,
            Curse.ColorPair(1),
            Curse.ColorPair(2),
            Curse.ColorPair(3),
            Curse.ColorPair(4),
        };

        static readonly int cursorStyles = Curse.ColorPair(6) | (int)TextAttribute.REVERSE;
        public Dump dump;

        public DisplayVM(Dump dump)
        {
            this.dump = dump;
            initDumpWindow();
        }

        public void initDumpWindow()
        {
            int nbLine = dump.MemorySize / bytePerLine;
        }

        static int getX(int index)
        {
            return (index % bytePerLine) * byteLen;
        }

        static int getY(int index)
        {
            return index / bytePerLine;
        }

        static int getStyle(int owner)
        {
            if (owner >= 1 && owner <= styles.Length)
                return styles[owner];
            return 0;
        }

        public void PrintValue(byte value)
        {
            byte high, low;

            low = (byte)(value & 0xf);
            high = (byte)(value >> 4);
            PanelSettings.MemZone.AddCh(GetCharFromByte(high));
            PanelSettings.MemZone.AddCh(GetCharFromByte(low));
        }

        public void PrintCase(byte value, int x, int y)
        {
            PanelSettings.MemZone.Move(y, x);
            PrintValue(value);
        }

        public void PrintCase(int at)
        {
            int x, y, owner, style;
            byte value;

            if (at <= 0 || at >= dump.Memory.Length)
            {
                Logger.Log.WriteLine("case out of bound {0}", at);
                return ;
            }
            x = getX(at);
            y = getY(at);
            owner = dump.getOwner(at);
            style = getStyle(owner);
            value = dump.Memory[at];
            PanelSettings.MemZone.Attron(style);
            PrintCase(value, x, y);
            PanelSettings.MemZone.Attroff(style);
        }

        public void PrintMemoryChunk(int at, int len)
        {
            Logger.Log.WriteLine("print chunk at {0} len {1}", at, len);
            for (int i = 0; i < len; i++)
            {
                PrintCase(i + at);
            }
            PanelSettings.MemZone.Refresh();
        }

        public void PrintAllMemory() => PrintMemoryChunk(0, dump.MemorySize);

        byte[] lastProcMap = null;
        public void PrintProc()
        {
            byte[] procMap = new byte[dump.MemorySize];

            foreach (KeyValuePair<int, Processus> proc in dump.ProcessusList)
            {
                procMap[proc.Value.Pos] = 1;
            }
            if (lastProcMap == null)
            {
                PanelSettings.MemZone.Attron(cursorStyles);
                for (int i = 0; i < dump.MemorySize; i++)
                {
                    if (procMap[i] == 1)
                    {
                        PrintCase(dump.Memory[i], getX(i), getY(i));
                    }
                }
                PanelSettings.MemZone.Attroff(cursorStyles);
            }
            else
            {
                for (int i = 0; i < dump.MemorySize; i++)
                {
                    if (procMap[i] == 1)
                    {
                        PanelSettings.MemZone.Attron(cursorStyles);
                        PrintCase(dump.Memory[i], getX(i), getY(i));
                    }
                    else if (lastProcMap[i] == 1)
                    {
                        PanelSettings.MemZone.Attroff(cursorStyles);
                        PrintCase(i);
                    }
                }
                PanelSettings.MemZone.Attroff(cursorStyles);
            }
            lastProcMap = procMap;
            PanelSettings.MemZone.Refresh();
        }

        public void OnMemChange(object source, int at, int len)
        {
            PrintMemoryChunk(at, len);
        }

        object lockCycle = new object();
        public void OnCycleUpdate(object _source, CycleUpdateEventArgs _e)
        {
            lock (lockCycle)
            {
                PrintProc();
            }
        }

        static char GetCharFromByte(byte val)
        {
            if (val > 9)
                return (char)(val + 'a' - 10);
            return (char)(val + '0');
        }
    }
}
