function test_ind() {
	info "test with indirect"
	warning "no live should be print"
	$1 test_ind.cor -dump 100
	info "done"
}

function test_rg() {
	info "test with reg"
	warning "no live should be print"
	$1 test_rg.cor -dump 100
	info "done"
}

function run() {
	title "\nTets st opcode\n"
	test_ind $1
	test_rg $1
}
