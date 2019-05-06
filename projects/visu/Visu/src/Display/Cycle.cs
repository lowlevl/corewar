using System;
using Ncurse;
using XmlParser;

namespace Display
{
    public class CycleDisplay
    {
        int cycle, nextCycle, nbLive, nbCheck, toDie;
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
        static readonly int cycleHeight = 5;
        static readonly int titleYStart = Math.Min(Curse.Lines / 3, Players.EndAt);
        static readonly public int EndAt = titleYStart + titleHeight + cycleHeight + 1;

        public void OnCycleUpdate(object _source, CycleUpdateEventArgs e)
        {
            Logger.Log.WriteLine("cycle: {0}", e);
            cycle = e.CurrentCycle;
            if (nextCycle != e.NextCheckCycle)
            {
                nextCycle = e.NextCheckCycle;
                renderNextCycle();
            }
            if (nbLive != e.NbLive)
            {
                nbLive = e.NbLive;
                renderLive();
            }
            if (toDie != e.CycleToDie)
            {
                toDie = e.CycleToDie;
                renderToDie();
            }
            if (nbCheck != e.NbCheck)
            {
                nbCheck = e.NbCheck;
                renderNbCheck();
            }
            renderCycle();
            cycleWin.Refresh();
        }

        void renderCycle()
        {
            cycleWin.Mvprintw(1, 0, "cycle: " + cycle);
            // cycleWin.RedrawLine(1);
        }

        void renderNextCycle()
        {
            cycleWin.Mvprintw(2, 0, "next check: " + nextCycle);
            // cycleWin.RedrawLine(2);
        }

        void renderLive()
        {
            cycleWin.Mvprintw(0, 0, "live: " + nbLive);
        }

        void renderToDie()
        {
            cycleWin.Mvprintw(3, 0, "To Die: " + toDie);
        }

        void renderNbCheck()
        {
            cycleWin.Mvprintw(4, 0, "Nb Check: " + nbCheck);
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
