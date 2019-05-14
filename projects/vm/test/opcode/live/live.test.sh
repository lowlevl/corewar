function test_live() {
	info "test live with 1 and 42"
	$1 live.cor --live
	info "done"
}

function run() {
	title "\nTest live opcode\n"
	test_live $1
}
