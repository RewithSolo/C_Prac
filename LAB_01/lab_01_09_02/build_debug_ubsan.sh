#!/bin/bash

clang -std=c99 -fsanitize=undefined -g -fno-omit-frame-pointer -o app.exe ./*.c

