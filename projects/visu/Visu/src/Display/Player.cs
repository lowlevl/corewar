using System;
using System.Timers;
using Ncurse;

namespace Display
{
    class Player
    {
        public int id;
        public bool winner = false;
        public string name;
        int idx;
        static readonly public int Height = 5;
        static readonly public int Width = 50;
        Window win;
        Timer timerTaunt = new Timer(500);
        int nbEventTaunt = 0;
        bool tauntSwitch = false;
        static object dispLock = new object();
        string tauntMessage = null;
        public int NbProc = 0;
        public int NbLive = 0;

        public Player(int id, string name, int idx, Window win)
        {
            this.id = id;
            this.name = name;
            this.win = win;
            this.idx = idx;
            timerTaunt.AutoReset = true;
            timerTaunt.Elapsed += onTauntInterval;
            timerTaunt.Enabled = false;
        }

        public void RenderName()
        {
            win.Move(0, 0);
            win.Attron(Players.styles[idx]);
            if (name.Length > Player.Width)
                win.Printw(name.Substring(0, Player.Width));
            else
                win.Printw(name);
            win.Attroff(Players.styles[idx]);
        }
        public int RenderId() => win.Mvprintw(1, 0, String.Format("id: {0}", id));
        public int RenderProc() => win.Mvprintw(2, 0, String.Format("nb proc: {0}", NbProc));
        public int RenderLive() => win.Mvprintw(3, 0, String.Format("nb live: {0}", NbLive));

        public void Render()
        {
            RenderName();
            RenderId();
            RenderLive();
            RenderProc();
            win.Refresh();
        }

        public void RefreshPanel() => win.Refresh();

        public void taunt(string msg)
        {
            nbEventTaunt = 0;
            tauntSwitch = false;
            tauntMessage = msg;
            timerTaunt.Enabled = true;
            win.Mvprintw(4, 0, String.Format("💬  {0}", msg));
        }

        public void live() {
            NbLive++;
            RenderLive();
            win.Refresh();
        }

        void onTauntInterval(object _source, EventArgs e)
        {
            lock (dispLock)
            {
                nbEventTaunt++;
                win.Move(4, 0);
                if (nbEventTaunt > 10)
                {
                    win.ClearToEol();
                    timerTaunt.Enabled = false;
                }
                else
                {
                    if (tauntSwitch == true)
                        win.Printw(string.Format("💬  {0}", tauntMessage));
                    else
                        win.Printw(string.Format("   {0}", tauntMessage));
                    tauntSwitch = !tauntSwitch;
                }
                win.Refresh();
            }
        }
    }
}
