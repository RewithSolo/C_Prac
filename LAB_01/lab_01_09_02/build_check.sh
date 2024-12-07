#!/bin/bash

echo "- - - - - - - Debug Build - - - - - - - -"
bash ./build_debug.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo "- - - - - - - - - - - - - - - - - - - - -"
bash ./clean.sh

echo "- - - - - - Debug Asan Build - - - - - -"
bash ./build_debug_asan.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo "- - - - - - - - - - - - - - - - - - - - -"
bash ./clean.sh

echo "- - - - - - Debug San Build - - - - - -"
bash ./build_debug_msan.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo "- - - - - - - - - - - - - - - - - - - - -"
bash ./clean.sh

echo "- - - - - - Debug UbSan Build - - - - - -"
bash ./build_debug_ubsan.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo "- - - - - - - - - - - - - - - - - - - - -"
bash ./clean.sh

echo "- - - - - - Release Build - - - - - -"
bash ./build_release.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo "- - - - - - - - - - - - - - - - - - - - -"
bash ./collect_coverage.sh


