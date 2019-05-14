.name "test carry"
.comment "test carry for lld"

                # carry status
lld %42, r2     # 0
lld %0, r2      # 1
lld :test, r2   # 0
st r3, :test
test: live %42
lld :test, r2   # 1
