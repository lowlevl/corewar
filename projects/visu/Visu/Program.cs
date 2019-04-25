using System;
using System.Collections.Generic;
using System.Xml;
using System.Threading;
using Ncurse;
using Display;
using Com;
using XmlParser;
using Command;
using Logger;

public class CorewarVisu
{
    const string ip = "127.0.0.1";
    const int port = 8080;
    const string logfile = ".corewarvisu.log";
    static SocketHandler handler;
    static Parser parser;
    static Dump dump;
    static DisplayVM disp;
    static Players players;
    static CycleDisplay cycle;
    static Display.End end;
    static Option command;

    static Dictionary<string, OptionArgv> options = new Dictionary<string, OptionArgv> {
        { "proc", new OptionArgv("p", "proc", "disable processus cursor") },
        { "name", new OptionArgv("n", "name", "user name", 1) }
    };

    static CorewarVisu()
    {
        command = new Option(ref options);
        Console.WriteLine("bonjour 🎩");
        Log.InitLog(logfile);
    }

    static void initNcurse()
    {
        Log.WriteLine("initNCurse");
        Curse.initscr();
        Curse.start_color();
        Curse.curs_set(CursorMode.INVISIBLE);
        Curse.init_pair(1, ColorCode.RED, ColorCode.DARK_GREY);
        Curse.init_pair(2, ColorCode.BLUE_1, ColorCode.DARK_GREY);
        Curse.init_pair(3, ColorCode.GREEN, ColorCode.DARK_GREY);
        Curse.init_pair(4, ColorCode.YELLOW, ColorCode.DARK_GREY);
        Curse.init_pair(5, ColorCode.DARK_GREY_1, ColorCode.DARK_GREY);
        Curse.init_pair(6, ColorCode.WHITE, ColorCode.DARK_GREY);
        Curse.noecho();
        Window.Standar.SetColor(5);
    }

    static void quit()
    {
        Log.WriteLine("quit");
        Log.StopLog();
        Curse.endwin();
        Console.WriteLine("bye, 👋");
    }

    static void setupEventListener()
    {
        // setup
        handler.SocketMessage += parser.OnSocketMessage;

        parser.MemChunkUpdate += dump.OnMemChunkChange;
        parser.MapChunkUpdate += dump.OnMapChunkUpdate;

        parser.NewPlayer += players.OnNewPlayer;

        parser.AffEvent += players.OnPlayerTaunt;

        if (!command.ParsedOption.ContainsKey("proc"))
        {
            parser.ProcUpdate += dump.OnProcUpdate;
            parser.DeadProcEvent += players.OnDeadProc;
        }

        parser.CycleUpdate += disp.OnCycleUpdate;
        parser.CycleUpdate += cycle.OnCycleUpdate;
        parser.LiveEvent += players.OnPlayerLive;

        parser.WinnerResult += end.OnWinner;

        dump.ChangeEvent += disp.OnMemChange;
        dump.NewProcEvent += players.OnNewProc;

    }

    static void initClass()
    {
        Log.WriteLine("init class");
        handler = new SocketHandler(ip, port);
        parser = new Parser();
        dump = new Dump();
        disp = new DisplayVM(dump);
        players = new Players();
        cycle = new CycleDisplay();
        end = new Display.End();
    }

    static void getUserInput()
    {
        int ch;
        do
        {
            ch = Curse.getch();
        } while (ch != 'q');
    }

    static void ParseCommand(string[] argv)
    {
        Log.WriteLine("Parse command");
        try
        {
            command.ParseArgv(argv);
        }
        catch (UnknowOptionException uoe)
        {
            Console.Error.WriteLine(uoe.Message);
            command.Usage();
            Environment.Exit(1);
        }
        catch (MissingArgumentException mae)
        {
            Console.Error.WriteLine(mae.Message);
            command.Usage();
            Environment.Exit(1);
        }
    }
    static public int Main(string[] argv)
    {
        ParseCommand(argv);
        initNcurse();
        string[] name;
        if (command.ParsedOption.TryGetValue("name", out name))
            Welcome.confirmUserReady(name[1]);
        else
            Welcome.confirmUserReady();
        PanelSettings.InitPanel();
        initClass();
        setupEventListener();

        // brain
        Window.Standar.Refresh();
        Thread thread = handler.SetupListen();
        thread.Start(1000);
        getUserInput();

        handler.CloseServer();
        thread.Join();
        quit();
        return 0;
    }
}
