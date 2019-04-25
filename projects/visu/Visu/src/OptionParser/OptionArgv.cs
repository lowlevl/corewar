namespace Command
{
    public class OptionArgv
    {
        readonly static string shortPrefix = "-";
        readonly static string longPrefix = "--";
        static int maxLenShort;
        static int maxLenLong;

        readonly public string shortOpt;
        readonly public string longOpt;
        readonly public string helpter;
        readonly public int nbArg;
        public OptionArgv(string shortOpt, string longOpt, string helpter, int nbArg)
        {
            this.shortOpt = shortPrefix + shortOpt;
            this.longOpt = longPrefix + longOpt;
            this.helpter = helpter;
            this.nbArg = nbArg + 1;

            if (this.shortOpt.Length > maxLenShort)
                maxLenShort = this.shortOpt.Length;
            if (this.longOpt.Length > maxLenLong)
                maxLenLong = this.longOpt.Length;
        }

        public OptionArgv(string shortOpt, string longOpt, string helpter)
            : this(shortOpt, longOpt, helpter, 0)
        { }


        public bool isEqual(string option)
        {
            return option == shortOpt || option == longOpt;
        }

        public string getUsage()
        {
            string format = "{0,-" + maxLenShort + "}|{1,-" + maxLenLong + "} : ";

            if (nbArg > 1)
                return string.Format(format + "wanted arg {2} : {3}", shortOpt, longOpt, nbArg, helpter);
            return string.Format(format + "{2}", shortOpt, longOpt, helpter);
        }
    }
}
