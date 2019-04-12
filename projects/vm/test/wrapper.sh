#!/bin/bash

source $(dirname $0)/utils.sh

BUILD_SCRIPT=$(dirname $0)/build.sh
TEST_SCRIPT=$(dirname $0)/test.sh

COREWAR_PATH=""
ASM_PATH=""

function usage() {
	echo "$0" 1>&2
	echo "-c|--corewar corewar # path to the corewar bin" 1>&2
	echo "-a|--asm asm         # path to the asm bin" 1>&2
	exit 1
}

for arg in $@
do
	case $arg in
		-c|--corewar)
			COREWAR_PATH=$2
			shift
			shift
		;;
		-a|--asm)
			ASM_PATH=$2
			shift
			shift
		;;
		*)
			OTHER="$OTHER $arg"
		;;
	esac
done

if [ "$COREWAR_PATH" == "" ] && [ "$ASM_PATH" == "" ]
then
	echo "missing corewar or asm"
	usage
fi

echo "OTHER        : $OTHER"
echo "COREWAR_PATH : $COREWAR_PATH"
echo "ASM_PATH     : $ASM_PATH"

title "\nBuilding cor file for test ...\n"
bash $BUILD_SCRIPT $ASM_PATH

title "\nBegining test ...\n"
bash $TEST_SCRIPT $COREWAR_PATH $OTHER
