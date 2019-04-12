.name "test basic"
.comment "test xor with basic test"

ld %1, r2 # 01
ld %2, r3 # 10
ld %3, r4 # 11

xor r2, r3, r5 # value should be '3'
xor r2, r4, r6 # value should be '2'
xor r3, r4, r7 # value should be '1'
xor r8, r8, r8 # value should be '0'
xor r3, r3, r8 # value should be '0'
