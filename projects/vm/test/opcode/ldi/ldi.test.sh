function test_basic() {
	info "test ldi opcode basic"
	$1 test_basic.cor -dump 100
	info "done"
}

function run() {
	title "\nTest ldi opcode\n"
	test_basic $1
}
