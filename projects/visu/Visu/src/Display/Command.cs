using Ncurse;
using System;

namespace Display
{
    public class Command
    {
        Window winCom;
        Window winTitle;
        int commandYStart = CycleDisplay.EndAt;

        static string[] commands = new string[] {
            "Press 'q' to quit"
        };
        static int height = commands.Length;
        static Symbol title = new Symbol(new string[] {
            "_________                                           .___      ",
            "\\_   ___ \\  ____   _____   _____ _____    ____    __| _/______",
            "/    \\  \\/ /  _ \\ /     \\ /     \\\\__  \\  /    \\  / __ |/  ___/",
            "\\     \\___(  <_> )  Y Y  \\  Y Y  \\/ __ \\|   |  \\/ /_/ |\\___ \\ ",
            " \\______  /\\____/|__|_|  /__|_|  (____  /___|  /\\____ /____  >",
            "        \\/             \\/      \\/     \\/     \\/      \\/    \\/ "
        });

        public Command() {
            winTitle = Window.CreateSubWindow(PanelSettings.InfoZone, title.Height, Player.Width, 1, commandYStart);
            winTitle.SetColor(1);

            winCom = Window.CreateSubWindow(PanelSettings.InfoZone, height, Player.Width, 1, commandYStart + title.Height);
            winCom.SetColor(6);

            title.DrawSymbolAt(winTitle, 0, 0);
        }

        public void PrintCommand() {
            for (int i = 0; i < height; i++) {
                winCom.Mvprintw(i, 0, commands[i]);
            }
            winCom.Refresh();
        }
    }
}
