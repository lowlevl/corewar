function test_basic() {
	info "test basic and"
	$1 test_basic.cor
	info "done"
}
function test_direct() {
	info "test basic and"
	$1 test_direct.cor
	info "done"
}
function test_ind() {
	info "test basic and"
	$1 test_ind.cor
	info "done"
}

function run() {
	title "\nTest and opcode\n"
	test_basic $1
	test_direct $1
	test_ind $1
}
