#!/bin/bash

POSTFIX="./postfix"
RPN="./RPN"
FILENAME="calculations.txt"

calculate () {
	local infix="$1"
	postfix_result=$("$POSTFIX" "$infix" | awk '{$1=$1};1')

	echo "Infix:  " "$infix"
	echo "Postfix:" "$postfix_result"
	echo "Result: " $("$RPN" "$postfix_result")
	echo ""
}

# calculate "3+5+2*3+(7+3)"

mass_calculate () {
	while read line; do
		calculate "$line"
	done < "$FILENAME"
}

mass_calculate