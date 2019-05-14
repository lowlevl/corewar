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

function test_lld_g() {
	info "test lld gui"
	$1 test_lld_g.cor
	info "done"
}

function test_neg() {
	info "test lld gui"
	$1 test_neg.cor
	info "done"
}

function test_carry() {
	info "test lld gui"
	$1 test_carry.cor
	info "done"
}

function run() {
	title "\nTest lld opcode\n"
	test_direct $1
	test_ind $1
	test_lld_g $1
	test_neg $1
	test_carry $1
}
