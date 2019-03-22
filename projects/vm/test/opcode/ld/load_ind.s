.name "load ind"
.comment "load indirect value"


ld %42, r2
st r2, :yolo
ld :yolo, r2

yolo: aff r1
