.name "test no live"
.comment "test zjump opcode"

and r2, r2, r2 # set carry to 1
zjmp %0
live %1
