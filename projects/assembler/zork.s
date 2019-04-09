.name		"Zorky !"
.comment	"Bebe zork :3"

# Infinite loop
#.byte 0x09 # Code for `zjmp`
#.byte 0x00 # Byte n1 of the parameter
#.byte 0x00 # Byte n2 of the parameter

#lo-ol:	st r1, :lo-lol
#		sti r1, %:lo-lol, %1

l2:		sti r1, %:live, %1
		and r1, %2, r3

live:	live %1
		zjmp %:live
