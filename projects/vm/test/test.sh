#!/bin/bash

CYAN="\e[36m"
BOLD="\e[1m"
RESET="\e[0m"
YELLOW_L="\e[93m"

TITLE="${CYAN}${BOLD}"
INFO="${YELLOW_L}"

function usage() {
	echo "$0 corewar" 1>&2
	echo "--opcode=type1,type2,... test only precised opcode" 1>&2
	exit 1
}

function realpath() {
	echo "$(cd "$(dirname "$1")" && pwd)/$(basename "$1")"
}

function info() {
	printf "${INFO}$*${RESET}\n"
}

function title() {
	printf "${TITLE}$*${RESET}\n"
}

OPCODE_TO_TEST="."
COREWAR_PATH=""

for arg in "$@"
do
	case $arg in
		--opcode=*)
			OPCODE_TO_TEST="($( echo ${arg#*=} | tr ',' '|'))"
			;;
		*)
			COREWAR_PATH=$arg
			;;
	esac
done


if [ "$COREWAR_PATH" == "" ]
then
	usage
fi

REGEX_FILE=".*\.test.sh"
TEST_SCRIP=$(find . -type f -regex $REGEX_FILE | grep -E "$OPCODE_TO_TEST")
COREWAR_PATH=$(realpath $COREWAR_PATH)

echo "TEST_SCRIP     : $TEST_SCRIP"
echo "COREWAR_PATH   : $COREWAR_PATH"
echo "OPCODE_TO_TEST : $OPCODE_TO_TEST"
echo "REGEX_FILE     : $REGEX_FILE"

for file in $TEST_SCRIP
do
	(
		source $file
		cd $(dirname $file)
		run $COREWAR_PATH
	)
done
