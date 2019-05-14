#!/bin/bash

source $(dirname $0)/utils.sh

BUILD_SCRIPT=$(dirname $0)/build.sh
TEST_SCRIPT=$(dirname $0)/test.sh

COREWAR_PATH=""
ASM_PATH=""
PROG_NAME="$0"


function usage() {
	echo "${PROG_NAME}" 1>&2
	echo "-c|--corewar corewar # path to the corewar bin" 1>&2
	echo "-a|--asm asm         # path to the asm bin" 1>&2
	exit $1
}

while getopts ":c:a:h" option
do
	echo ${option} ${OPTARG}
	case "${option}" in
		h) usage 0;;
		c|--corewar)
			echo "core"
			COREWAR_PATH=${OPTARG};;
		a|--asm)
			echo "asm"
			ASM_PATH=${OPTARG};;
	esac
done

shift $((OPTIND - 1))
if [ "${COREWAR_PATH}" == "" ] && [ "${ASM_PATH}" == "" ]
then
	echo "missing corewar or asm"
	usage
fi

echo "OTHER        : $@"
echo "COREWAR_PATH : ${COREWAR_PATH}"
echo "ASM_PATH     : ${ASM_PATH}"

title "\nBuilding cor file for test ...\n"
bash ${BUILD_SCRIPT} ${ASM_PATH}

title "\nBegining test ...\n"
bash ${TEST_SCRIPT} ${COREWAR_PATH} $@
