function test_ind() {
	info "test with indirect"
	warning "no live should be print"
	$1 test_ind.cor
	info "done"
}

function test_rg() {
	info "test with reg"
	warning "no live should be print"
	$1 test_rg.cor
	info "done"
}

function run() {
	title "\nTets st opcode\n"
	test_ind $1
	test_rg $1
}
