#!/bin/bash

cd func_tests/scripts || exit
./func_tests.sh
cd ../../
echo "----------------------"
echo "General tests coverage"
gcov app-exec5.c
echo "----------------------"
./clean.sh
