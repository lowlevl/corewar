function test_all() {
	info "test multiple config for sub"
	$1 test_all.cor
	info done
}

function test_outside() {
	info "test outside reg for sub"
	$1 test_outside.cor
	info done
}

function run() {
	title "\nTest sub opcode\n"
	test_all $1
	test_outside $1
}
