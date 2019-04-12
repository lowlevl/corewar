.name "test basic"
.comment "test and with basic test"

ld %1, r2
ld %2, r3
ld %3, r4

and r2, r3, r5 # value should be '0'
and r2, r4, r6 # value should be '1'
and r3, r4, r7 # value should be '2'
