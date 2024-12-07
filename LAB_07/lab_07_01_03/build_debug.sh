#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c src/main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Werror -Wfloat-equal -Wfloat-conversion -g -c src/funcs.c
gcc -g -o app.exe main.o funcs.o

