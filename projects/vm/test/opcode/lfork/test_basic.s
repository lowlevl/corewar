.name "test basic"
.comment "test basic lfork command"

sti r1, %:live, %1
live: live %1
lfork: lfork %:live
