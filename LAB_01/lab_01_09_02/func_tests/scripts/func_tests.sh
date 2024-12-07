#!/bin/bash

count=0

for file in ./../data/*_in.txt; do
    p_file="${file[*]:10}"
    if [[ "$file" =~ pos_[0-9][0-9]_in\.txt ]]; then
        num="${p_file[*]:4:2}"
        file_output="./../data/pos_$num""_out.txt"
        
        ./pos_case.sh "$file" "$file_output"
        checker=$?

        if [[ $checker -eq 0 ]]; then
            echo "$p_file passed"
        elif [[ $checker -eq 1 ]]; then
            echo "$p_file failed"
            count=$((count+1))
        fi

    elif [[ "$file" =~ neg_[0-9][0-9]_in\.txt ]]; then

        ./neg_case.sh "$file"
        checker=$?

        if [[ $checker -eq 0 ]]; then
            echo "$p_file passed"
        elif [[ $checker -eq 1 ]]; then
            echo "$p_file failed"
            count=$((count+1))
        fi

    fi
done

echo Failed tests: $count
exit $count
