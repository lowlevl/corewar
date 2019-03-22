.name "test rg"
.comment "test st with reg in second params"

ld %42, r2
st r2, r1
sti r1, :yolo, %1
yolo: live %1
