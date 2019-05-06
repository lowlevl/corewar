function test_load_1() {
	info "the reg should have '42' in it\n"
	$1 load_1.cor
	info "done"
}
function test_load_all() {
	info "all the reg should have '42' in it\n"
	$1 load_all.cor
	info "done"
}

function test_outside() {
	info "test to load '42' in reg 0 and 17\n"
	info "no write reg should be displayed "
	$1 load_outside.cor
	info "done"
}

function test_ind() {
	info "test to load to indirect\n"
	$1 load_ind.cor --dump 1500
	info "done"
}

function test_neg() {
	info "test to load to indirect\n"
	$1 test_neg.cor --dump 1500
	info "done"
}

function test_carry() {
	info "test to load to indirect\n"
	$1 test_carry.cor
	info "done"
}

function run() {
	title "\nTest ld opcode\n"
	warning "corewar should be compiled with DEBUG_WRITE to 1"
	test_load_1 $1
	test_load_all $1
	test_outside $1
	test_ind $1
	test_neg $1
	test_carry $1
}
