.name "test all"
.comment "test multiple config with add opcode"

# load value in reg
ld %42, r2
ld %22, r3

# test add carry must be 0
add r2, r3, r4
add r4, r4, r5

# test add carry must be 1
add r6, r7, r8
