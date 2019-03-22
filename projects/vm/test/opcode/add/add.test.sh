function test_all() {
	info "test multiple config for add"
	$1 test_all.cor
	info done
}

function run() {
	title "\nTest add opcode\n"
	test_all $1
}
