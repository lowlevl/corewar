.name "test basic"
.comment "basic test for opcode ldi"

ldi %:live, %1, r2 # load 42 in r2
ldi %0, %0, r2
live: live %42
test: ldi :live, r3, r4 # load
ldi r1, r1, r2 # should read at 2
