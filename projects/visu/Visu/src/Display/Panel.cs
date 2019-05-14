using System;
using Ncurse;

namespace Display
{
    public class PanelSettings
    {
        static public readonly int InfoWidth = 70;
		static Window MainInfoZone;
		static public Window InfoZone;
        static Window MainMemZone;
        static public Window MemZone;


        static public void InitPanel() {
            MainInfoZone = Window.CreateSubWindow(Window.Standar, Curse.Lines, InfoWidth, 0, 0);
            MainMemZone = Window.CreateSubWindow(Window.Standar, Curse.Lines, Curse.Cols - InfoWidth, InfoWidth, 0);

            MainInfoZone.box(WinAttribute.ACS_VLINE, WinAttribute.ACS_HLINE);
            MainMemZone.box(WinAttribute.ACS_VLINE, WinAttribute.ACS_HLINE);

            InfoZone = Window.CreateDerWindow(MainInfoZone, Curse.Lines - 2, InfoWidth - 2, 1, 1);
            MemZone = Window.CreateDerWindow(MainMemZone, Curse.Lines - 2, Curse.Cols - InfoWidth - 2, 1, 1);
            MemZone.SetColor(5);
        }
    }
}
