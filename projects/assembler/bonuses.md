# <> Corewar - ASM

## Bonus list
  - Very verbose output, `gcc-like`, with:
    => Colors
    => Help
    => Explanations
    => Arrow to point where the error is
  - `.byte` command, which takes an `indirect` argument,
and places the value on one byte, right there in the binary.
Example:
```s
# Infinite loop
.byte 0x09 # Code for `zjmp`
.byte 0x00 # Byte n1 of the parameter
.byte 0x00 # Byte n2 of the parameter
```

Use cases for the `.byte` command:
  - Having a modified `aff` which can read directly a null terminated string
from the memory.
  - Padding in the binary.
  - Having an OP-Code being also a parameter for another OP-Code.
Example:
```s
and r1, %0, r1
zjmp %1
.byte 0x0
.byte 0x0
.byte 0x0
.byte 0x1

```
