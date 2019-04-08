.name		"Zorky !"
.comment	"Bebe zork :3"

#lo-ol:	st r1, :lo-lol
#		sti r1, %:lo-lol, %1

l2:		sti r1, %:live, %1
		and r1, %2, r3

live:	live %4
		zjmp %:live

