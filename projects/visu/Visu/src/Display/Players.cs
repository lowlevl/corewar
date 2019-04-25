using System;
using System.Timers;
using System.Collections.Generic;
using XmlParser;
using Ncurse;

namespace Display
{
    public class Players
    {
        Window titleWin;
        Window playersWin;
        static readonly public int maxPlayer = 4;
        readonly static public int playersHeight = maxPlayer * Player.Height;
        static readonly public int[] styles = new int[] {
            Curse.ColorPair(1),
            Curse.ColorPair(2),
            Curse.ColorPair(3),
            Curse.ColorPair(4),
        };

        static readonly Symbol title = new Symbol(new string[]{
            "__________.__                                    " ,
            "\\______   |  | _____  ___.__. ___________ ______" ,
            " |     ___|  | \\__  \\<   |  _/ __ \\_  __ /  ___/" ,
            " |    |   |  |__/ __ \\___  \\  ___/|  | \\\\___ \\" ,
            " |____|   |____(____  / ____|\\___  |__| /____  >" ,
            "                    \\/\\/         \\/          \\/ "
        });
        static public int titleHeight { get { return title.Height; } }
        int nbPlayer = 0;
        Dictionary<int, Player> players = new Dictionary<int, Player>();

        readonly static public int EndAt = playersHeight + title.Height + 2;

        public Players()
        {
            titleWin = Window.CreateSubWindow(PanelSettings.InfoZone, title.Height, Player.Width, 1, 1);
            titleWin.SetColor(1);

            playersWin = Window.CreateSubWindow(PanelSettings.InfoZone, playersHeight, Player.Width, 1, title.Height + 1);
            playersWin.SetColor(6);

            title.DrawSymbolAt(titleWin, 0, 0);
        }

        public void OnNewPlayer(object source, PlayerEventArgs e)
        {
            int y = title.Height + 1 + (nbPlayer * Player.Height);
            Player newPlayer;

            if (nbPlayer >= maxPlayer)
                return;
            newPlayer = new Player(e.Id, e.Name, nbPlayer,
                Window.CreateSubWindow(playersWin, Player.Height, Player.Width, 1, y));
            players.Add(e.Id, newPlayer);
            newPlayer.Render();
            nbPlayer++;
        }

        public void OnNewProc(object source, ref Processus proc)
        {
            Player p;
            if (players.TryGetValue(proc.PlayerId, out p))
            {
                p.NbProc++;
                p.RenderProc();
            }
            else
            {
                throw new MissingMemberException(String.Format("missing player {0}", proc.Id));
            }
        }
        public void OnPlayerTaunt(object source, AffEventArgs e)
        {
            Player player;

            if (players.TryGetValue(e.PlayerId, out player))
            {
                player.taunt(e.Message);
            }
        }

        public void OnDeadProc(object _source, DeadProcEventArgs e)
        {
            Player p;

            if (players.TryGetValue(e.PlayerId, out p))
            {
                p.NbProc--;
                p.RenderProc();
            }
        }

        public void OnPlayerLive(object _source, LiveEventArgs e)
        {
            Player p;

            if (players.TryGetValue(e.PlayerId, out p))
            {
                p.live();
            }
        }
    }
}
