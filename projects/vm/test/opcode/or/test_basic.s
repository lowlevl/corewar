.name "test basic"
.comment "test or with basic test"

ld %1, r2
ld %2, r3
ld %3, r4

or r2, r3, r5 # value should be '3'
or r2, r4, r6 # value should be '3'
or r3, r4, r7 # value should be '3'
or r8, r3, r9 # value should be '2'
or r8, r8, r10 # value should be '0' and carry 1
