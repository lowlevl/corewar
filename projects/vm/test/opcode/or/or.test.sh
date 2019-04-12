function test_basic() {
	info "test basic or"
	$1 test_basic.cor
	info "done"
}

function run() {
	title "\nTest or opcode\n"
	test_basic $1
}
