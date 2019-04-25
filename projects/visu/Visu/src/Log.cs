using System;
using System.IO;

namespace Logger
{
    public class Log
    {
        static StreamWriter w;
        static bool isInit = false;
        static object writeLock = new object();

        public static void WriteLine(string format, params object[] arg)
            => WriteLine(string.Format(format, arg));

        public static void WriteLine(string message)
            => Write(message + "\n");

        public static void Write(string format, params object[] arg)
            => Write(string.Format(format, arg));

        public static void Write(string message) {
            CheckIfInit();
            lock (writeLock) {
                w.Write(message);
            }
        }

        public static void InitLog(string filename) {
            if (isInit)
                throw new Exception("Cannot initialise multiple logger " + isInit + filename);
            w = new StreamWriter(filename);
            isInit = true;
        }

        public static void StopLog() {
            CheckIfInit();
            w.Close();
            isInit = false;
        }

        static void CheckIfInit() {
            if (!isInit)
                throw new Exception("Logger not init");
        }
    }
}
