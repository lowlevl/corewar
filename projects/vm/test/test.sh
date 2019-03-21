#!/bin/bash

function usage() {
	echo 'missing path for corewar exe' 1>&2
	exit 1
}

function realpath() {
	echo "$(cd "$(dirname "$1")" && pwd)/$(basename "$1")"
}

if [ $# -eq 0 ]
then
	usage
fi

test_scrip=$(find . -type f -regex '.*\.test.sh')

export COREWAR_PATH=$(realpath $1)

echo $test_scrip
echo $COREWAR_PATH

for file in $test_scrip
do
	(
		source $file
		echo $file
		cd $(dirname $file)
		run $COREWAR_PATH
	)
done
