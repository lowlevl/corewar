.name "test neg"
.comment "test load neg ind"

live: live %42
ld :live, r2
ld -512, r2 # should read at 0
ld -1000, r2 # should read at 4096 - 488
ld -500, r2 # should read at 4096 - 500
