#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c product.c
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c product_array.c
gcc -g -o app.exe main.o product.o product_array.o

