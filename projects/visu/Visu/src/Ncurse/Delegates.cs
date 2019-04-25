using System;

namespace Ncurse
{
    class Delegates
    {
        public delegate IntPtr initscr();
        public delegate int endwin();
        public delegate bool isendwin();
        public delegate int cbreak();
        public delegate int nocbreak();
        public delegate int echo();
        public delegate int noecho();
        public delegate int halfdelay(int t);
        public delegate int raw();
        public delegate int noraw();
        public delegate void noqiflush();
        public delegate void qiflush();
        public delegate int typeahead(IntPtr fd);
        public delegate int timeout(int delay);
        public delegate int wtimeout(IntPtr win, int delay);
        public delegate int notimeout(IntPtr win, bool bf);
        public delegate int keypad(IntPtr win, bool bf);
        public delegate int meta(IntPtr win, bool bf);
        public delegate int intrflush(IntPtr win, bool bf);
        public delegate int clearok(IntPtr win, bool bf);
        public delegate int idlok(IntPtr win, bool bf);
        public delegate void idcok(IntPtr win, bool bf);
        public delegate void immedok(IntPtr win, bool bf);
        public delegate int leaveok(IntPtr win, bool bf);
        public delegate int wsetscrreg(IntPtr win, int top, int bot);
        public delegate int scrollok(IntPtr win, bool bf);
        public delegate int nl();
        public delegate int nonl();
        public delegate int setscrreg(int top, int bot);
        public delegate int refresh();
        public delegate int doupdate();
        public delegate int wrefresh(IntPtr win);
        public delegate int redrawwin(IntPtr win);
        public delegate int wredrawln(IntPtr win, int beg_line, int num_lines);
        public delegate int wnoutrefresh(IntPtr win);
        public delegate int move(int line, int col);
        public delegate int addch(int ch);
        public delegate int addstr(string s);
        public delegate int waddstr(IntPtr win, string s);
        public delegate int wmove(IntPtr win, int line, int col);
        public delegate int waddch(IntPtr win, int ch);
        public delegate int attron(int attrs);
        public delegate int attroff(int attrs);
        public delegate int attrset(int attrs);
        public delegate int getch();
        public delegate int get_wch(out int sequence);
        public delegate int ungetch(int ch);
        public delegate int mvgetch(int y, int x);
        public delegate bool has_colors();
        public delegate int start_color();
        public delegate int init_pair(short pair, short f, short b);
        public delegate int use_default_colors();
        public delegate int COLOR_PAIRS();
        //public delegate uint getmouse(out Curses.MouseEvent ev);
        //public delegate uint ungetmouse(ref Curses.MouseEvent ev);
        public delegate int mouseinterval(int interval);
        public delegate IntPtr mousemask(IntPtr newmask, out IntPtr oldMask);

        public delegate IntPtr subwin(IntPtr ParentWin, int height, int width, int y0, int x0);
        public delegate int box(IntPtr Win, int vAttrs, int hAttrs);
        public delegate int mvwprintw(IntPtr Win, int line, int col, string s);
        public delegate int wprintw(IntPtr Win, string s);
        public delegate int wborder(IntPtr Win, int left, int right, int top, int bottom, int top_left, int top_right, int bottom_left, int bottom_right);
        public delegate int init_color(short n, short r, short g, short b);
        public delegate int wbkgd(IntPtr Win, int n);
        public delegate int wattron(IntPtr Win, int attrs);
        public delegate int wattroff(IntPtr Win, int attrs);
        public delegate int curs_set(int mode);
        public delegate IntPtr derwin(IntPtr ParentWin, int height, int width, int y0, int x0);
        public delegate IntPtr newwin(int height, int width, int y0, int x0);
        public delegate int wclrtoeol(IntPtr win);
        public delegate int wclear(IntPtr win);
        public delegate int werase(IntPtr win);
    }
}
