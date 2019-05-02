.name "test ind 2"
.comment "test st with -4"

st r1, 512 # should read at 0
st r1, 504 # should read at 504
st r1, 1000 # should read at 488
