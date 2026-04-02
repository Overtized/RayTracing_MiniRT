#!/bin/bash
# script_wrong_maps.sh
# Script to try all wrong maps from MiniRT
# Usage: ./script_wrong_maps.sh /path/to/miniRT

# Verify that there is the executable
if [ -z "$1" ]; then
	echo "Usage: $0 /path/to/miniRT_executable"
	exit 1
fi

MINIRT="$1"

# Check if the executable exists and is runnable
if [ ! -x "$MINIRT" ]; then
	echo "Error: $MINIRT is not executable"
	exit 1
fi

RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RESET="\033[0m"

# Folder with invalid maps
MAP_DIR="scenes/wrong_maps"

# Get all files in the folder (any extension)
MAPS=("$MAP_DIR"/*)

TOTAL=${#MAPS[@]}
OK_COUNT=0
FAIL_COUNT=0

echo -e "${YELLOW}==== Testing invalid maps ====${RESET}"

for map in "${MAPS[@]}"; do
	echo -n "Test of $map : "
	OUTPUT=$("$MINIRT" "$map" 2>&1 1>/dev/null)
	RET=$?

	if [ $RET -ne 0 ]; then
		echo -e "${GREEN}OK${RESET}\t(program returned an error as expected)"
		echo "  -> Message: $OUTPUT"
		((OK_COUNT++))
	else
		echo -e "${RED}FAIL${RESET}\t(program did NOT detect the error!)"
		((FAIL_COUNT++))
	fi
done

echo -e "${YELLOW}==== Summary ====${RESET}"
echo -e "Total tests: $TOTAL"
echo -e "${GREEN}Passed: $OK_COUNT${RESET}"
echo -e "${RED}Failed: $FAIL_COUNT${RESET}"
