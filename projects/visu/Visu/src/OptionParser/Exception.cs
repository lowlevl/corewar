namespace Command
{
    public class UnknowOptionException : System.Exception
    {
        public UnknowOptionException() { }
        public UnknowOptionException(string option)
            : base(string.Format("unknow option {0}", option))
        {}

        public UnknowOptionException(string message, System.Exception inner) : base(message, inner) { }
        protected UnknowOptionException(
            System.Runtime.Serialization.SerializationInfo info,
            System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }

    public class MissingArgumentException : System.Exception
    {
        public MissingArgumentException() { }
        public MissingArgumentException(string forOpt, int wanted)
            : base(string.Format("missing argument for {0}, wanted {1}", forOpt, wanted))
        { }
        public MissingArgumentException(string message, System.Exception inner) : base(message, inner) { }
        protected MissingArgumentException(
            System.Runtime.Serialization.SerializationInfo info,
            System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
