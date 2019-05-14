.name "test ind"
.comment "test ind for and"

                        # reg   | carry
and :live2, :live3, r2  # 1     | 0
live1: live %42
and :live1, :live2, r2  # 1     | 0
live2: live %42
and :live2, :live3, r2  # 1     | 0
live3: live %42
and :live2, :live3, r2  # 1     | 0

and -512, 0, r2     # should read at 0
and -500, 0, r2     # should read at -500
and -1000, 0, r2    # should read at -488
