#!/bin/bash

echo -e "\033[1m [ Debug Build ] \033[0m"
bash ./build_debug.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo -e "\033[1m-----------------------\033[0m\n"
bash ./clean.sh

echo -e "\033[1m [ Debug Asan Build ] \033[0m"
bash ./build_debug_asan.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo -e "\033[1m-----------------------\033[0m\n"
bash ./clean.sh

echo -e "\033[1m [ Debug San Build ] \033[0m"
bash ./build_debug_msan.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo -e "\033[1m-----------------------\033[0m\n"
bash ./clean.sh

echo -e "\033[1m [ Debug UbSan Build ] \033[0m"
bash ./build_debug_ubsan.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo -e "\033[1m-----------------------\033[0m\n"
bash ./clean.sh

echo -e "\033[1m [ Release Build ] \033[0m"
bash ./build_release.sh
cd func_tests/scripts || exit
bash ./func_tests.sh
cd ../../
echo -e "\033[1m-----------------------\033[0m\n"
bash ./collect_coverage.sh


