.comment "test sti with indirect"
.name "test ind"

ld %-1, r2
sti r2, :live, %1
live: live %1
