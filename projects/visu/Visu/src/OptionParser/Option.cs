using System;
using System.Text;
using System.Collections.Generic;

namespace Command
{
    public class Option
    {
        Dictionary<string, OptionArgv> Options;
        Dictionary<string, string[]> result;
        List<string> others;

        public Option(ref Dictionary<string, OptionArgv> options)
        {
            UpdateOptions(ref options);
        }

        public void UpdateOptions(ref Dictionary<string, OptionArgv> options)
        {
            Options = options;
        }

        public void ParseArgv(string[] argv)
        {
            result = new Dictionary<string, string[]>();
            others = new List<string>();

            for (int i = 0; i < argv.Length; i++)
            {
                if (argv[i][0] == '-')
                    ParseOpt(argv, ref i);
                else
                    others.Add(argv[i]);
            }
        }

        void ParseOpt(string[] argv, ref int i)
        {
            foreach (KeyValuePair<string, OptionArgv> tupleOption in Options)
            {
                OptionArgv optionArgv = tupleOption.Value;

                if (optionArgv.isEqual(argv[i]))
                {
                    string[] res = new string[optionArgv.nbArg];
                    int j = 0;

                    if (argv.Length - i < optionArgv.nbArg)
                        throw new MissingArgumentException(argv[i], optionArgv.nbArg);
                    for (; j < optionArgv.nbArg; j++)
                        res[j] = argv[j + i];
                    i += j - 1;
                    result[tupleOption.Key] = res;
                    return;
                }
            }
            throw new UnknowOptionException(argv[i]);
        }

        public Dictionary<string, string[]> ParsedOption
        {
            get { return result; }
        }

        public string[] GetOthers()
        {
            return others.ToArray();
        }

        public void Usage()
        {
            foreach (KeyValuePair<string, OptionArgv> option in Options)
            {
                Console.Error.WriteLine(option.Value.getUsage());
            }
        }
    }
}
