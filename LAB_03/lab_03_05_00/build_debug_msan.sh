#!/bin/bash

clang -std=c99 -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c main.c
clang -std=c99 -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c funcs.c
clang -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g -o app.exe main.o funcs.o
