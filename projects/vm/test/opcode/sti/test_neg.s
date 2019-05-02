.name "test neg value"
.comment "look for -100"

sti r1, %0, %-100
sti r1, %0, %-1000 # should write at 4096 - 488
sti r1, %0, %-500 # should write at 4096 - 500
sti r1, %0, %1000 # should write at 488
sti r1, %0, %500 # should write at 500
