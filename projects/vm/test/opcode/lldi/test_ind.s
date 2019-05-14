.name "test ind"
.comment "test ind for lldi"

live1: live %42
lldi :live1, %0, r2
lldi :live2, %0, r2
live2: live %42
