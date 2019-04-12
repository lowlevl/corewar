function test_basic() {
	info "test lldi with basic test"
	$1 test_basic.cor
	info "done"
}

function run() {
	title "\nTest lldi opcode\n"
	test_basic $1
}
