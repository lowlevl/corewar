using System;
using System.Runtime.InteropServices;

namespace Ncurse
{
    public partial class Curse
    {
        static Window main_window;
        static UnmanagedLib curse_lib;
        static NativeMethods methods;
        static object displayLock = new object();

        static int lines, cols;
        static IntPtr curse_handle, plines, pcols, stdscr, curscr;

        #region SETUP
        static void LoadMethods()
        {
            var libs = UnmanagedLib.IsMacOsPlat
                ? new string[] { "libncurses.dylib" }
                : new string[] { "libncurses.6.so", "libncurses.5.so" };
            curse_lib = new UnmanagedLib(libs);
            methods = new NativeMethods(curse_lib);
        }

        static void FindNCurse()
        {
            LoadMethods();

            curse_handle = methods.UnmanagedLibrary.NativeLibraryHandle;

            stdscr = readStaticPtr("stdscr");
            curscr = getPtr("curscr");
            plines = getPtr("LINES");
            pcols = getPtr("COLS");
        }

        static public Window initscr()
        {
            FindNCurse();

            main_window = new Window(methods.initscr());
            try
            {
                consoleGetDims(out lines, out cols);
            }
            catch (DllNotFoundException)
            {
                endwin();
                Console.WriteLine("unables to find mono curse lib");
                Environment.Exit(1);
            }
            return main_window;
        }

        #endregion

        public static int Lines
        {
            get
            {
                return Marshal.ReadInt32(plines);
            }
        }

        public static int Cols
        {
            get
            {
                return Marshal.ReadInt32(pcols);
            }
        }

        public static int ColorPair(int n)
        {
            return n * 256;
        }

        internal static IntPtr getPtr(string key)
        {
            var ptr = curse_lib.LoadSymbol(key);

            if (ptr == IntPtr.Zero)
                throw new Exception("Could not load ht key " + key);
            return ptr;
        }

        internal static IntPtr readStaticPtr(string key)
        {
            var ptr = getPtr(key);
            return Marshal.ReadIntPtr(ptr);
        }

        internal static void consoleGetDims(out int l, out int c)
        {
            l = Marshal.ReadInt32(plines);
            c = Marshal.ReadInt32(pcols);
        }

        internal static IntPtr consoleGetStdscr() => stdscr;
        internal static IntPtr consoleGetCurscr()
        {
            return Marshal.ReadIntPtr(curscr);
        }

        public static int waddCh(IntPtr win, int ch)
        {
            if (ch < 127 || ch > 0xffff)
            {
                lock (displayLock)
                {
                    return waddch(win, ch);
                }
            }
            return waddstr(win, new string((char)ch, 1));
        }

        public static int waddStr(IntPtr win, string format, params object[] args)
        {
            string s = string.Format(format, args);
            return waddstr(win, s);
        }

        public static int addCh(int ch) => waddCh(stdscr, ch);

        public static int addStr(string format, params object[] args) => waddStr(stdscr, format, args);


        #region METHODS

        public static int waddstr(IntPtr win, string s)
        {
            lock (displayLock)
            {
                return methods.waddstr(win, s);
            }
        }
        public static int waddch(IntPtr win, int ch)
        {
            lock (displayLock)
            {
                return methods.waddch(win, ch);
            }
        }

        public static int addstr(string s) => methods.addstr(s);
        public static int endwin() => methods.endwin();
        public static int wrefresh(IntPtr Win)
        {
            lock (displayLock)
            {
                return methods.wrefresh(Win);
            }
        }
        public static int getch() => methods.getch();
        public static int attron(int attrs) => methods.attron(attrs);
        public static int attroff(int attrs) => methods.attroff(attrs);
        public static IntPtr subwin(IntPtr ParentWin, int height, int width, int y0, int x0) => methods.subwin(ParentWin, height, width, y0, x0);

        public static int box(IntPtr Win, int attrsv, int attrsh)
        {
            lock (displayLock)
            {
                return methods.box(Win, attrsv, attrsh);
            }
        }
        public static int box(IntPtr Win, WinAttribute attrsv, WinAttribute attrsh) => box(Win, (int)attrsv, (int)attrsh);

        public static int mvwprintw(IntPtr Win, int line, int col, string s)
        {
            lock (displayLock)
            {
                return methods.mvwprintw(Win, line, col, s);
            }
        }

        public static int wprintw(IntPtr Win, string s)
        {
            lock (displayLock)
            {
                return methods.wprintw(Win, s);
            }
        }
        public static int wmove(IntPtr Win, int line, int col)
        {
            lock (displayLock)
            {
                return methods.wmove(Win, line, col);
            }
        }
        public static int wborder(IntPtr Win, int left, int right, int top, int bottom, int top_left, int top_right, int bottom_left, int bottom_right) => methods.wborder(Win, left, right, top, bottom, top_left, top_right, bottom_left, bottom_right);
        public static int start_color() => methods.start_color();
        public static int init_color(short colorID, short r, short g, short b) => methods.init_color(colorID, r, g, b);

        public static int init_pair(short pairID, short forID, short backID) => methods.init_pair(pairID, forID, backID);
        public static int init_pair(short pairID, ColorCode forground, ColorCode background) => init_pair(pairID, (short)forground, (short)background);

        public static int wattron(IntPtr Win, int attrs)
        {
            lock (displayLock)
            {
                return methods.wattron(Win, attrs);
            }
        }
        public static int wattroff(IntPtr Win, int attrs)
        {
            lock (displayLock)
            {
                return methods.wattroff(Win, attrs);
            }
        }
        public static int wbkgd(IntPtr Win, int n)
        {
            lock (displayLock)
            {
                return methods.wbkgd(Win, n);
            }
        }

        public static int curs_set(CursorMode mode) => methods.curs_set((int)mode);
        public static IntPtr derwin(IntPtr Win, int height, int width, int y0, int x0) => methods.derwin(Win, height, width, y0, x0);
        public static IntPtr newwin(int height, int width, int y0, int x0) => methods.newwin(height, width, y0, x0);
        public static int wclrtoeol(IntPtr win)
        {
            lock (displayLock)
            {
                return methods.wclrtoeol(win);
            }
        }
        public static int wredrawln(IntPtr win, int beg_line, int count)
        {
            lock (displayLock)
            {
                return methods.wredrawln(win, beg_line, count);
            }
        }

        public static int wclear(IntPtr win)
        {
            lock (displayLock)
            {
                return methods.wclear(win);
            }
        }
        public static int noecho() => methods.noecho();
        #endregion
    }
}
