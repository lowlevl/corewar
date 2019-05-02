function test_basic() {
	info "test ldi opcode basic"
	$1 test_basic.cor --dump 100
	info "done"
}

function test_neg() {
	info "test ldi opcode basic"
	$1 test_neg.cor --dump 155
	info "done"
}

function run() {
	title "\nTest ldi opcode\n"
	test_basic $1
	test_neg $1
}
