.name "test direct"
.comment "test direct for and"

and %2, %2, r2              # value in reg should be 2, carry 0
and %1, %2, r2              # value in reg should be 0, carry 1
and %2147483648, %50, r2    # value in reg should be 0, carry 1
