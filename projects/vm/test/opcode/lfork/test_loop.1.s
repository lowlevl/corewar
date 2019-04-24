.name "test loop"
.comment "test big loop for lfork"

sti r1, %:live, %1
and r5, r5, r5
live: live %1
fork %:live
zjmp %:live
