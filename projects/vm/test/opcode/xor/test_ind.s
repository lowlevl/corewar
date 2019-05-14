.name "test ind"
.comment "test ind for xor"

                        # reg   | carry
xor :live2, :live3, r2  # 0     | 1
live1: live %42
xor :live1, :live2, r2  # 0     | 1
live2: live %42
xor :live2, :live3, r2  # 0     | 1
live3: live %42
xor :live2, :live3, r2  # 0     | 1

xor -512, 0, r2     # should read at 0
xor -500, 0, r2     # should read at -500
xor -1000, 0, r2    # should read at -488
