function test_print_a() {
	info "vm: first player should print 'A'\n"
	$1 print_a.cor
	info "done"
}

function test_print_hello() {
	info "vm: first player should print 'hello'\n"
	$1 print_hello.cor
	info "done"
}

function run() {
	title "\nTest aff opcode\n"
	test_print_a $1
	test_print_hello $1
}
