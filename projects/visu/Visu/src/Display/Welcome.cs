using Ncurse;
using System;
using System.Timers;
using Logger;

namespace Display
{
    public class Welcome
    {
        static readonly string[] title = new string[] {
            "      ::::::::   ::::::::  :::::::::  :::::::::: :::       :::     :::     :::::::::\n",
            "    :+:    :+: :+:    :+: :+:    :+: :+:        :+:       :+:   :+: :+:   :+:    :+:\n" ,
            "   +:+        +:+    +:+ +:+    +:+ +:+        +:+       +:+  +:+   +:+  +:+    +:+ \n" ,
            "  +#+        +#+    +:+ +#++:++#:  +#++:++#   +#+  +:+  +#+ +#++:++#++: +#++:++#:   \n" ,
            " +#+        +#+    +#+ +#+    +#+ +#+        +#+ +#+#+ +#+ +#+     +#+ +#+    +#+   \n" ,
            "#+#    #+# #+#    #+# #+#    #+# #+#         #+#+# #+#+#  #+#     #+# #+#    #+#    \n" ,
            "########   ########  ###    ### ##########   ###   ###   ###     ### ###    ###     \n"
        };
        static readonly int titleWidth = title[0].Length;
        static readonly int titleHeight = title.Length;

        static readonly string subTitle = "Press Enter when the corewar is ready !";
        static Timer timerSub = new Timer(500);
        static bool subSwitch = false;

        static string name = null;

        static Welcome() {
            timerSub.Enabled = false;
            timerSub.Elapsed += OnTimerInterval;
        }

        static void printTitle(int x, int y) {
            x = x - titleWidth / 2;
            y = y - titleHeight / 2;
            Log.WriteLine("x({0}) y({1})", x, y);
            for (int i = 0; i < titleHeight; i++)
            {
                Window.Standar.Mvprintw(y + i, x, title[i]);
            }
        }

        static void printSubTitle(int x, int y) {
            x = x - subTitle.Length / 2;
            Window.Standar.Mvprintw(y, x, subTitle);
        }

        static void displayWelcomeScreen()
        {
            printTitle(Curse.Cols / 2, Curse.Lines / 2 - 5);
        }

        static void waitUserInput()
        {
            int ch;

            displayWelcomeScreen();
            do
            {
                ch = Curse.getch();
                if (ch == 410) {
                    Window.Standar.Clear();
                    displayWelcomeScreen();
                }
            } while (ch != '\n');
        }

        static void OnTimerInterval(object _source, EventArgs e) {
            subSwitch = !subSwitch;
            int x = Curse.Cols / 2 - subTitle.Length / 2;
            int y = Curse.Lines / 2;
            if (subSwitch) {
                Window.Standar.Mvprintw(y, x, subTitle);
                if (name != null) {
                    string welcome = string.Format("Welcome {0}", name);
                    Window.Standar.Mvprintw(y + 2, Curse.Cols / 2 - welcome.Length / 2, welcome);
                }
            } else {
                Window.Standar.Move(y, x);
                Window.Standar.ClearToEol();

                Window.Standar.Move(y + 2, x);
                Window.Standar.ClearToEol();
            }
            Window.Standar.Refresh();
        }

        public static void confirmUserReady(string name) {
            Window.Standar.SetColor(1);
            timerSub.Enabled = true;
            Welcome.name = name;
            waitUserInput();
            timerSub.Enabled = false;
            Window.Standar.SetColor(5);
            Window.Standar.Clear();
        }

        public static void confirmUserReady() => confirmUserReady(null);
    }
}
