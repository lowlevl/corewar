namespace Ncurse
{
    public enum TextAttribute : uint
    {
        NORMAL = 0x0,
        STANDOUT = 0x10000,
        UNDERLINE = 0x20000,
        REVERSE = 0x40000,
        BLINK = 0x80000,
        DIM = 0x100000,
        BOLD = 0x200000,
        PROTECT = 0x1000000,
        INVIS = 0x800000,

        ATTRIBUTES = 4294967040,
        CHAR_TEXT = 255,
        ALT_CHARSET = 4194304,
        HORIZONTAL = 33554432,

        LEFT = 67108864,
        LOW = 134217728,
        RIGHT = 268435456,
        TOP = 536870912,

        VERTICAL = 1073741824,
        ITALIC = 2147483648
    }
}