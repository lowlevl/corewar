.name "test neg"
.comment "test neg for lfork"

live: live %42
lfork %:live
live %42
lfork %-1024