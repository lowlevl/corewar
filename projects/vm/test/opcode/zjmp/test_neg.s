.name "test neg"
.comment "test neg for zjmp"

add r3, r3, r2
zjmp %-1000 # should jump at 4096 - 1000
