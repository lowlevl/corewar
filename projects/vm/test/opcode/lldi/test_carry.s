.name "test carry"
.comment "test carry for lldi"

                        # carry status
res: lldi %0, %0, r2    # 1
lldi %1, %-1, r2        # 1
lldi %:res, %0, r2      # 0
lldi :test, %0, r2      # 0
st r3, :test
test: live %42
lldi :test, %0, r2      # 1
