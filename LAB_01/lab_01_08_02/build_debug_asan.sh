#!/bin/bash

clang -std=c99 -fsanitize=address -g -fno-omit-frame-pointer -o app.exe ./*.c

