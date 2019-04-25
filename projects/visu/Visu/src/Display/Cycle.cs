using System;
using Ncurse;
using XmlParser;

namespace Display
{
    public class CycleDisplay
    {
        int cycle;
        int nextCycle;
        Window titleWin;
        Window cycleWin;

        static readonly string[] title = new string[] {
            "_________              .__          ",
            "\\_   ___ \\___.__. ____ |  |   ____  ",
            "/    \\  \\<   |  |/ ___\\|  | _/ __ \\ ",
            "\\     \\___\\___  \\  \\___|  |_\\  ___/ ",
            " \\______  / ____|\\___  >____/\\___  >",
            "        \\/\\/         \\/          \\/ "
        };
        static readonly int titleWidth = title[0].Length;
        static readonly int titleHeight = title.Length;
        static readonly int cycleHeight = 2;
        static readonly int titleYStart = Math.Min(Curse.Lines / 3, Players.EndAt);
        static readonly public int EndAt = titleYStart + titleHeight + cycleHeight + 1;

        public void OnCycleUpdate(object _source, CycleUpdateEventArgs e)
        {
            cycle = e.CurrentCycle;
            if (nextCycle != e.NextCheckCycle)
            {
                nextCycle = e.NextCheckCycle;
                renderNextCycle();
            }
            renderCycle();
            cycleWin.Refresh();
        }

        void renderCycle()
        {
            cycleWin.Mvprintw(0, 0, string.Format("cycle: {0}", cycle));
            cycleWin.RedrawLine(0);
        }

        void renderNextCycle()
        {
            cycleWin.Mvprintw(1, 0, string.Format("next check: {0}", nextCycle));
            cycleWin.RedrawLine(1);
        }

        void printTitle()
        {
            for (int i = 0; i < titleHeight; i++)
            {
                titleWin.Mvprintw(i, 0, title[i]);
            }
        }

        public CycleDisplay()
        {
            titleWin = Window.CreateSubWindow(PanelSettings.InfoZone, titleHeight, titleWidth, 1, titleYStart);
            cycleWin = Window.CreateSubWindow(PanelSettings.InfoZone, cycleHeight, Player.Width, 1, titleYStart + titleHeight);

            titleWin.SetColor(1);
            cycleWin.SetColor(6);

            printTitle();
        }
    }
}
