.name "test ind"
.comment "test ind for or"

                        # reg   | carry
or :live2, :live3, r2  # 1     | 0
live1: live %42
or :live1, :live2, r2  # 1     | 0
live2: live %42
or :live2, :live3, r2  # 1     | 0
live3: live %42
or :live2, :live3, r2  # 1     | 0

or -512, 0, r2     # should read at 0
or -500, 0, r2     # should read at -500
or -1000, 0, r2    # should read at -488
