function test_carry() {
	info "test zjump"
	warning "no live should be print"
	$1 test_carry.cor
	info "done"
}

function test_no_live() {
	info "test zjump loop"
	warning "no live should be print"
	$1 test_no_live.cor
	info "done"
}

function test_loop(){
	info "test zjump loop adr"
	warning "no live should be print"
	$1 test_loop.cor
	info "done"
}

function test_neg(){
	info "test zjump loop adr"
	warning "no live should be print"
	$1 test_neg.cor
	info "done"
}

function run() {
	title "\nTest zjmp opcode\n"
	test_no_live $1
	test_loop $1
	test_carry $1
	test_neg $1
}
