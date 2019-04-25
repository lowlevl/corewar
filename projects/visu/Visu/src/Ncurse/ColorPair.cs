using System;

namespace Ncurse
{
    public class ColorPair
    {
        public short pairId;
        ColorCode Forground;
        ColorCode Background;

        public ColorPair(short pairId, ColorCode forground, ColorCode background)
        {
            this.pairId = pairId;
            Forground = forground;
            Background = background;

            InitPair(pairId, forground, background);
            Console.Error.WriteLine(pairId);
        }

        public void SetForground(ColorCode forground)
        {
            Forground = forground;
            InitPair();
        }

        public void SetBackground(ColorCode background)
        {
            Background = background;
            InitPair();
        }

        public int InitPair() => InitPair(pairId, Forground, Background);

        public static int InitPair(short pairId, ColorCode forground, ColorCode Background) => Curse.init_pair(pairId, forground, Background);
    }
}
