using System;

namespace Ncurse
{
    public class Window
    {
        readonly public static Window Standar;
        readonly public static Window Current;
        public readonly IntPtr Handle;
        int height, width;

        public int Height { get { return height; } }
        public int Width { get { return width; } }

        static Window()
        {
            Curse.initscr();
            Standar = new Window(Curse.consoleGetStdscr(), Curse.Lines, Curse.Cols);
            Current = new Window(Curse.consoleGetCurscr());
        }

        internal Window(IntPtr handle)
        {
            Handle = handle;
        }

        internal Window(IntPtr handle, int height, int width)
        {
            Handle = handle;
            this.height = height;
            this.width = width;
        }

        #region CREATE_WINDOW_CLASS

        static public Window CreateSubWindow(Window parent, int height, int width, int x, int y)
        {
            IntPtr handle = Curse.subwin(parent.Handle, height, width, y, x);
            return new Window(handle, height, width);
        }

        static public Window CreateSubWindowCentered(Window parent, int height, int width, int x, int y)
        {
            IntPtr handle = Curse.subwin(parent.Handle, height, width, y - height / 2, x - width / 2);
            return new Window(handle, height, width);
        }

        static public Window CreateNewWindow(int height, int width, int x, int y)
        {
            IntPtr handle = Curse.newwin(height, width, y, x);
            return new Window(handle, height, width);
        }

        static public Window CreateDerWindow(Window parent, int height, int width, int x, int y)
        {
            IntPtr handle = Curse.derwin(parent.Handle, height, width, y, x);
            return new Window(handle, height, width);
        }

        #endregion

        #region METHODS

        public int Move(int y, int x) => Curse.wmove(Handle, y, x);
        public int AddCh(int c) => Curse.waddCh(Handle, c);
        public int Attron(int attrs) => Curse.wattron(Handle, attrs);
        public int Attroff(int attrs) => Curse.wattroff(Handle, attrs);
        public int Mvprintw(int y, int x, string s) => Curse.mvwprintw(Handle, y, x, s);
        public int Printw(string s) => Curse.wprintw(Handle, s);

        public int SetColor(int colorPairId) => Curse.wbkgd(Handle, Curse.ColorPair(colorPairId));
        public int SetColor(ColorPair pair) => Curse.wbkgd(Handle, Curse.ColorPair(pair.pairId));

        public int Refresh() => Curse.wrefresh(Handle);
        public int box(int vAttrs, int hAttrs) => Curse.box(Handle, vAttrs, hAttrs);
        public int box(WinAttribute vAttrs, WinAttribute hAttrs) => Curse.box(Handle, (int)vAttrs, (int)hAttrs);
        public int ClearToEol() => Curse.wclrtoeol(Handle);
        public int RedrawLine(int line) => Curse.wredrawln(Handle, line, 1);
        public int RedrawLine(int line, int count) => Curse.wredrawln(Handle, line, count);
        public int Clear() => Curse.wclear(Handle);

        #endregion

    }
}
