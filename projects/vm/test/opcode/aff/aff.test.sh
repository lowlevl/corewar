function test_print_a() {
	printf "vm: first player should print 'A'\n\n"
	$1 print_a.cor
	printf "\ndone\n"
}

function tets_print_hello() {
	printf "vm: first player should print 'hello'\n\n"
	$1 print_hello.cor
	printf "\ndone\n"
}

function run() {
	test_print_a $1
	tets_print_hello $1
}
