#!/bin/bash

if [ $# -eq 0 ]
then
	echo "missing asm generator"
	exit 1
fi

asm_file=$(find . -type f -regex '.*\.s')

for file in $asm_file
do
	echo -ne "$file\n\t"
	$1 $file
done
