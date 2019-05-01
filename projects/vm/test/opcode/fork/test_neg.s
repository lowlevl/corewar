.name "test neg"
.comment "test neg value for fork"

fork %-1000 # should be set at 4096 - 488
live %42
fork %-512 # should be set at 0
live %42
fork %-500 # should be set at 4096 - 500