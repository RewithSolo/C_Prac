#!/bin/bash

clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g -c main.c
clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g -c product.c
clang -std=c99 -fsanitize=address -fno-omit-frame-pointer -g -c product_array.c
clang -fsanitize=address -fno-omit-frame-pointer -g -o app.exe main.o product.o product_array.o

