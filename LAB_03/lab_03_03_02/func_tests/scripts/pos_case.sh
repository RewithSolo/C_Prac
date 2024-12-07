#!/bin/bash

app="./../../app.exe"
file_input=$1
file_expected=$2
file_cur="cur.txt"

if [[ "$#" -ne 2 ]]; then
	exit 1
fi

"$app" < "$file_input" > "$file_cur"

./comparator.sh "$file_expected" "$file_cur"
compared=$?

exit "$compared"
