#!/bin/bash

cd func_tests/scripts || exit
./func_tests.sh
cd ../../
echo -e "\033[1m-----------------------\033[0m"
echo -e "\033[1m General tests coverage \033[0m"
gcov app-exec5.c
echo -e "\033[1m-----------------------\033[0m\n"
./clean.sh
