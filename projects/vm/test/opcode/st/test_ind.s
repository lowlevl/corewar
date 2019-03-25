.name "test ind"
.comment "test st with ind params"

ld %42, r2
st r2, :yolo
yolo: live %1
