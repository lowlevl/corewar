function test_direct() {
	info "test lld with direct"
	$1 test_direct.cor
	info "done"
}

function test_ind() {
	info "test lld with indirect"
	$1 test_ind.cor
	info "done"
}

function run() {
	title "\nTest lld opcode\n"
	test_direct $1
	test_ind $1
}
