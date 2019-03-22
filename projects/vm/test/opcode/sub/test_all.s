.name "test all"
.comment "test multiple config with sub opcode"

# load value in reg
ld %42, r2
ld %22, r3

# test sub carry must be 0
sub r2, r3, r4
sub r4, r4, r5

# test sub carry must be 1
sub r6, r7, r8
