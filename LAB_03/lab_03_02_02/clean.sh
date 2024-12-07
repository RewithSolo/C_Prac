#!/bin/bash

files="./func_tests/scripts/*.txt *.exe *.o *.gcda *.gcov *.c.gcov *.gcno"

for file in $files; do
	rm -f "$file"
done

