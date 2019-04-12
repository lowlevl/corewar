CYAN="\e[36m"
BOLD="\e[1m"
RESET="\e[0m"
YELLOW_L="\e[93m"
RED_L="\e[91m"
BLUE_L="\e[94m"

TITLE="${CYAN}${BOLD}"
INFO="${BLUE_L}"
WARN="${YELLOW_L}"
ERROR="${BOLD}${RED_L}"

function info() {
	printf "ℹ️  ${INFO}INFO:${RESET} $*\n"
}

function title() {
	printf "${TITLE}$*${RESET}\n"
}

function warning() {
	printf "⚠️  ${WARN}WARNING:$RESET $*\n"
}

function error() {
	printf "❌  ${ERROR}ERROR:$RESET $*\n"
}
