.name "Wormy, the worm :3"
.comment "I like to infect everyone <3"

ld %1, r2
st r2, 511

sti r1, %:life, %1
and %0, %0, r2

life: live %0
	fork %:dig
	zjmp %:life

dig:
#	live %0 # < Uncomment for cancer mode
	fork %:life
	live %0
