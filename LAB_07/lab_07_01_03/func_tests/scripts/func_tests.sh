#!/bin/bash

count=0

for file in ./../data/*_args.txt; do
    p_file="${file[*]:10}"
    if [[ "$file" =~ pos_[0-9][0-9]_args\.txt ]]; then
        num="${p_file[*]:4:2}"
        file_output="./func_tests/data/pos_$num""_out.txt"
        file="./func_tests/data/pos_$num""_args.txt"
        
        ./pos_case.sh "$file" "$file_output"
        checker=$?

        if [[ $checker -eq 0 ]]; then
            echo -e "\033[32m  $p_file passed \033[0m"
        elif [[ $checker -eq 1 ]]; then
            echo -e "\033[31m $p_file failed \033[0m"
            count=$((count+1))
        fi

    elif [[ "$file" =~ neg_[0-9][0-9]_args\.txt ]]; then

        ./neg_case.sh "$file"
        checker=$?

        if [[ $checker -eq 0 ]]; then
            echo -e "\033[32m $p_file passed \033[0m"
        elif [[ $checker -eq 1 ]]; then
            echo -e "\033[31m $p_file failed \033[0m"
            count=$((count+1))
        fi

    fi
done
if [[ $count -eq 0 ]]; then
    echo -e "\033[32m Failed tests: $count \033[0m"
else
    echo -e "\033[31m Failed tests: $count \033[0m"
fi

exit $count
