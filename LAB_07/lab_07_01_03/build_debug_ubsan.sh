#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g -c main.c
clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g -c funcs.c
clang -fsanitize=undefined -fno-omit-frame-pointer -g -o app.exe main.o funcs.o
