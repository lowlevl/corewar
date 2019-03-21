#!/bin/bash

if [ $# -eq 0 ]
then
	echo "missing asm generator"
	exit
fi

asm_file=$(find . -type f -regex '.*\.s')

for file in $asm_file
do
	$1 $file
done
