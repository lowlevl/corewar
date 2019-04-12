function test_basic() {
	info "test basic and"
	$1 test_basic.cor
	info "done"
}

function run() {
	title "\nTest and opcode\n"
	test_basic $1
}
