.name "test neg"
.comment "test neg for lldi"

live1: live %42
lldi %:live1, %1, r2 # should value 42 in r2
lldi %-1000, %0, r3 # should read value at 4096 - 1000
lldi %-500, %0, r3 # should read value at 4096 - 500