.name "test loop"
.comment "test zjump opcode"

and: and r2, r2, r2 # set carry to 1
zjmp %:and
live %1
