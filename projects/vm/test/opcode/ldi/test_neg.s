.name "test neg"
.comment "test neg ind for ldi"

live1: live %42
ldi :live1, %1, r2
ldi :live1, %-2, r3 # should read 0x 00 00 01 00
ldi %-1000, %0, r4 # should read at 4096 - 488
ldi %-500, %0, r4 # should read at 4096 - 500
ldi %1000, %0, r4 # should read at 488
ldi %500, %0, r4 # should read at 500