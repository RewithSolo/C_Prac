#!/bin/bash

app="./../../app.exe"
file_input=$1
file_output="output.txt"

if [[ "$#" -ne 1 ]]; then
	exit 1
fi

"$app" "$file_input" > "$file_output"

if [[ "$?" -lt 1 ]]; then
    compared=1
else
    compared=0
fi


exit "$compared"
