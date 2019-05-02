.name "test neg"
.comment "test neg for st"

st r1, -4 # should write at 4096 - 4
st r1, -512 # should write at 0
st r1, -1000 # should write at 4096 - 488
st r1, -500 # should write at 4096 - 500
