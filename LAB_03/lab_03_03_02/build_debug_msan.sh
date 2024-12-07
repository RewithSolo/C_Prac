#!/bin/bash

clang -std=c99 -fsanitize=memory -g -fno-omit-frame-pointer -fPIE -pie -o app.exe ./*.c

