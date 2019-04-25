using Ncurse;
using System;
using System.Threading;
using XmlParser;
using Logger;

namespace Display
{
    public class End
    {
        const string qToQuit = "Press 'q' to quit";

        Symbol trophy = new Symbol(new string[] {
            "  ___________  ",
            " '._==_==_=_.'",
            " .-\\:      /-.",
            "| (|:.     |) |",
            " '-|:.     |-'",
            "   \\::.    /",
            "    '::. .'",
            "      ) (",
            "    _.' '._",
            "   `\"\"\"\"\"\"\"`"
        });
        Symbol death = new Symbol(new string[] {
            "          .                                                      .           ",
            "        .n                   .                 .                  n.",
            "  .   .dP                  dP                   9b                 9b.    .",
            " 4    qXb         .       dX                     Xb       .        dXp     t",
            "dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb",
            "9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP",
            " 9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP",
            "  `9XXXXXXXXXXXXXXXXXXXXX'~   ~`OOO8b   d8OOO'~   ~`XXXXXXXXXXXXXXXXXXXXXP'",
            "    `9XXXXXXXXXXXP' `9XX'   DIE    `98v8P'   DIE    `XXP' `9XXXXXXXXXXXP'",
            "        ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~",
            "                        )b.  .dbo.dP'`v'`9b.odb.  .dX(",
            "                      ,dXXXXXXXXXXXb     dXXXXXXXXXXXb.",
            "                     dXXXXXXXXXXXP'   .   `9XXXXXXXXXXXb",
            "                    dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb",
            "                    9XXb'   `XXXXXb.dX|Xb.dXXXXX'   `dXXP",
            "                     `'      9XXXXXX(   )XXXXXXP      `'",
            "                              XXXX X.`v'.X XXXX",
            "                              XP^X'`b   d'`X^XX",
            "                              X. 9  `   '  P )X",
            "                              `b  `       '  d'",
            "                               `             '"
        });

        void PrintWinner(string Name, int id)
        {
            string winner = string.Format("And the winner is ... {0}({1})", id, Name);

            trophy.DrawSymbol(Window.Standar, Curse.Cols / 2, Curse.Lines / 2 - trophy.Height / 2 - 2);
            Window.Standar.Mvprintw(Curse.Lines / 2, Curse.Cols / 2 - winner.Length / 2, winner);
            PrintQ();
        }

        void PrintLoser()
        {
            string loser = "Everyone die";
            death.DrawSymbol(Window.Standar, Curse.Cols / 2, Curse.Lines / 2 - death.Height / 2 - 2);
            Window.Standar.Mvprintw(Curse.Lines / 2, Curse.Cols / 2 - loser.Length / 2, loser);
            PrintQ();
        }

        void PrintQ() => Window.Standar.Mvprintw(Curse.Lines / 2 + 2, Curse.Cols / 2 - qToQuit.Length / 2, qToQuit);

        public void OnWinner(object _source, WinnerResultEventArgs e)
        {
            Log.WriteLine("print winner {0} {1} {2}", e.HaveWinner, e.Name, e.Id);
            Thread.Sleep(1000);
            Window.Standar.Clear();
            Window.Standar.SetColor(4);
            if (e.HaveWinner)
                PrintWinner(e.Name, e.Id);
            else
                PrintLoser();
            Window.Standar.Refresh();
        }
    }
}
