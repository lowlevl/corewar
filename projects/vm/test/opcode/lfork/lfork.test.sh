function test_basic() {
	info "test basic test for lfork"
	$1 test_basic.cor -dump 15361
	info "done"
}

function test_loop() {
	info "test loop for lfork"
	$1 test_loop.cor --dump 5000
	info "done"
}

function test_loop1() {
	info "test loop for lfork"
	$1 test_loop.1.cor --dump 5000
	info "done"
}

function test_neg() {
	info "test loop for lfork"
	$1 test_neg.cor --dump 2020
	info "done"
}

function run() {
	title "\nTest lfork opcode\n"
	test_basic $1
	test_loop $1
	# test_loop1 $1
	test_neg $1
}
