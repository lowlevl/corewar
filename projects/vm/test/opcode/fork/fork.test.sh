function test_basic() {
	info "test basic test for fork"
	$1 test_basic.cor -dump 15361
	info "done"
}

function test_loop() {
	info "test loop for fork"
	$1 test_loop.cor
	info "done"
}

function test_fork_g()
{
	info "test fork gui"
	$1 test_fork_g.cor
	info "done"
}

function run() {
	title "\nTest fork opcode\n"
	echo $1
	test_basic $1
	test_loop $1
	test_fork_g $1
}
