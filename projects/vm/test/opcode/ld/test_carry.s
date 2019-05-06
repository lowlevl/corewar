.name "test carry"
.comment "test carry for ld"

                # carry status
ld %42, r2     # 0
ld %0, r2      # 1
ld :test, r2   # 0
st r3, :test
test: live %42
ld :test, r2   # 1
