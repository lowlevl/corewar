using System;
using Ncurse;

namespace Display
{
    public class Symbol
    {
        public string[] Text { get { return symbol; } }
        public int Height { get { return height; } }
        public int Width { get { return width; } }
        string[] symbol;
        int height;
        int width;

        public Symbol(string[] symbol)
        {
            if (symbol.Length == 0)
                throw new ArgumentException(string.Format("symbol should have at least 1 item"));
            InitSymbol(symbol, symbol.Length, symbol[0].Length);
        }

        public Symbol(string[] symbol, int height, int width) => InitSymbol(symbol, height, width);

        void InitSymbol(string[] symbol, int height, int width)
        {
            this.symbol = symbol;
            this.height = height;
            this.width = width;
        }

        public void DrawSymbol(Window win, int x, int y)
        {
            x = x - Width / 2;
            y = y - Height / 2;
            DrawSymbolAt(win, x, y);
        }
        public void DrawSymbolAt(Window win, int x, int y)
        {
            for (int i = 0; i < Height; i++)
            {
                win.Mvprintw(y + i, x, symbol[i]);
            }
            win.Refresh();
        }

    }
}
