.name "test direct"
.comment "test direct for xor"

xor %2, %2, r2              # value in reg should be 0, carry 1
xor %1, %2, r2              # value in reg should be 3, carry 0
xor %2147483648, %50, r2    # value in reg should be 32, carry 0
