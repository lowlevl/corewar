.name "test neg"
.comment "test neg value for lld"

live1: live %42
lld :live1, r2 # should write 01 00 00 00 in r2