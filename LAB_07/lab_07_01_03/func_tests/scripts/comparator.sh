#!/bin/bash


str1=()
str2=()
IFS=' '
reg="^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$"
while read -r y; do
  read -r -a array <<< "$y"
  for var in "${array[@]}"; do
    if [[ $var =~ $reg ]]; then
      str1+=("$var")
    fi
  done
done < "$1"

while read -r y; do
  read -r -a array <<< "$y"
  for var in "${array[@]}"; do
    if [[ $var =~ $reg ]]; then
      str2+=("$var")
    fi
  done
done < "$2"

if [ "${str1[*]}" == "${str2[*]}" ]; then
  exit 0
else
  exit 1
fi


