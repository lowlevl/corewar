using System;
using System.Runtime.InteropServices;

namespace Ncurse
{
    internal class UnmanagedLib
    {
        static bool IsMacOS, IsMono, Is64bit, IsLinux, IsNetCore;

        public static bool IsMacOsPlat => IsMacOS;

        const string LIBC_NAME = "libc";
        const string DARWIN = "Darwin";

        [DllImport(LIBC_NAME)]
        static extern int uname(IntPtr buf);

        static string GetUname()
        {
            var buffer = Marshal.AllocHGlobal(8192);
            try
            {
                if (uname(buffer) == 0)
                {
                    return Marshal.PtrToStringAnsi(buffer);
                }
                return string.Empty;
            }
            catch
            {
                return string.Empty;
            }
            finally
            {
                if (buffer != IntPtr.Zero)
                {
                    Marshal.FreeHGlobal(buffer);
                }
            }
        }

        static UnmanagedLib()
        {
            var platform = Environment.OSVersion.Platform;

            IsMacOS = platform == PlatformID.Unix && GetUname() == DARWIN;
            Is64bit = Marshal.SizeOf(typeof(IntPtr)) == 8;
            IsMono = Type.GetType("Mono.Runtime") != null;
            if (!IsMono)
                IsNetCore = Type.GetType("System.MathF") != null;
            IsLinux = platform == PlatformID.Unix && !IsMacOS;
        }

        readonly IntPtr handle;

        public IntPtr NativeLibraryHandle => handle;

        public UnmanagedLib(string[] LibPaths)
        {
            foreach (string lib in LibPaths)
            {
                handle = PlatformSpecificLoadLibrary(lib);
                if (handle == IntPtr.Zero)
                    throw new Exception(string.Format("Error loading native library \"{0}\"", lib));
            }
        }

        public IntPtr LoadSymbol(string symbolName)
        {
            if (IsMacOS)
            {
                return MacOSX.dlsym(handle, symbolName);
            }
            throw new InvalidOperationException("Unsupported platform.");
        }

        public T GetNativeMethodDelegate<T>(string methodName)
            where T : class
        {
            var ptr = LoadSymbol(methodName);
            if (ptr == IntPtr.Zero)
            {
                throw new MissingMethodException(string.Format("The native method \"{0}\" does not exist", methodName));
            }
            return Marshal.GetDelegateForFunctionPointer<T>(ptr);  // non-generic version is obsolete
        }

        // flags for dlopen
        const int RTLD_LAZY = 1;
        const int RTLD_GLOBAL = 8;

        static IntPtr PlatformSpecificLoadLibrary(string libraryPath)
        {
            if (IsMacOS)
            {
                return MacOSX.dlopen(libraryPath, RTLD_GLOBAL + RTLD_LAZY);
            }
            throw new InvalidOperationException("Unsupported platform.");
        }

        static class MacOSX
        {
            const string LIB_NAME = "libSystem.dylib";

            [DllImport(LIB_NAME)]
            internal static extern IntPtr dlopen(string filename, int flags);

            [DllImport(LIBC_NAME)]
            internal static extern IntPtr dlsym(IntPtr handle, string symbol);
        }
    }
}
