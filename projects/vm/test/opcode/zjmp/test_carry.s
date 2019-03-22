.name "test carry"
.comment "test carry behavior"

and r2, r2, r2 # set carry to 1
zjmp %:or

live: live %1

or: or r1, r1, r1 # set carry to 0

zjmp %:live
