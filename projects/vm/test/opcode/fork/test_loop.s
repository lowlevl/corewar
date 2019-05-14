.name "test loop"
.comment "test big loop for fork"

sti r1, %:live, %1
sti r1, %:live1, %1
sti r1, %:live2, %1
sti r1, %:live3, %1
sti r1, %:live4, %1
sti r1, %:live5, %1
sti r1, %:live6, %1
sti r1, %:live7, %1
sti r1, %:live8, %1
sti r1, %:live9, %1
sti r1, %:live10, %1
sti r1, %:live11, %1
sti r1, %:live12, %1
sti r1, %:live13, %1
sti r1, %:live14, %1
live: live %1
live1: live %1
live2: live %1
live3: live %1
live4: live %1
live5: live %1
live6: live %1
live7: live %1
live8: live %1
live9: live %1
live10: live %1
live11: live %1
live12: live %1
live13: live %1
live14: live %1
fork %:live
