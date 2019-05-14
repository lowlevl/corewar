.name "test reg"
.comment "test reg for lldi"

ld %42 r2
lldi %500, r2, r3 # should read value at 542
