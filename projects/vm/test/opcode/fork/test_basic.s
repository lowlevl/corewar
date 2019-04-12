.name "test basic"
.comment "test basic fork command"

sti r1, %:live, %1
live: live %1
fork: fork %:live
