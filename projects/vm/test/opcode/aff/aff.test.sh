function test_print_a() {
	printf "vm: first player should print 'A'\n\n"
	$1 print_a.cor
	printf "\ndone\n"
	read
}

function run() {
	test_print_a $1
}
