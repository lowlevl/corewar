.name "test direct"
.comment "test direct for or"

or %2, %2, r2              # value in reg should be 2, carry 0
or %1, %2, r2              # value in reg should be 3, carry 0
or %2147483648, %50, r2    # value in reg should be 32, carry 0
