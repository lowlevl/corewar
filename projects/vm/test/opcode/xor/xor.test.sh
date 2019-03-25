function test_basic() {
	info "test basic xor"
	$1 test_basic.cor
	info "done"
}

function run() {
	title "\nTest xor opcode\n"
	test_basic $1
}
