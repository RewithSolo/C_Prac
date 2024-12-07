#!/bin/bash


file_input=$1
file_expected=$2
file_cur="./func_tests/scripts/cur.txt"
app="./app.exe"
str=()

if [[ "$#" -ne 2 ]]; then
	exit 1
fi
cd ../../

while read -r y; do
  read -r -a array <<< "$y"
  for var in "${array[@]}"; do
      str+=("$var")
  done
done < "$1"

"$app" "${str[0]}" "${str[1]}" > "$file_cur"

./func_tests/scripts/comparator.sh "$file_expected" "$file_cur"

compared=$?

exit "$compared"
