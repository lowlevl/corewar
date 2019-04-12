.name		"Zorky !"
.comment	"Bebe zork :3"
.extend

#lo-ol:	st r1, :lo-lol
#		sti r1, %:lo-lol, %1
#
#l2:		sti r1, %:live, %1
#		and r1, %1, r1
#
#live:	live %1
#		zjmp %:live
#

# Empty number
and r1, -0, r0

# Empty label
#zjmp %:
#st r1, :
