.name "test basic"
.comment "test basic command with lldi"

lldi %:live, %1, r2
lldi %1, %:live, r3
live: live %42
