.name		"Zorky !"
.comment	"Bebe zork :3"

l2:		sti r1, %:live, %1
		and r1, %2, r3

live:	live %1
		zjmp %:live