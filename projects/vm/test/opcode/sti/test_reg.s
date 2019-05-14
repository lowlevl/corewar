.name "test reg"
.comment "test reg for sti"

ld %42, r2
sti r2, r2, r2 # should write at 42 * 2, 42
