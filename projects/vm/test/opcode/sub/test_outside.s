.name "test outside"
.comment "test outside reg idx"

# load value in reg
ld %42, r2
ld %22, r3

# test outise
sub r0, r2, r4
sub r2, r0, r4
sub r2, r3, r0

# test outise
sub r17, r2, r4
sub r2, r17, r4
sub r2, r3, r17
