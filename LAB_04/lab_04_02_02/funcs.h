#ifndef __FUNCS_H__
#define __FUNCS_H__
#include "errors.h"

#define S 256
#define W 20

// Ввод строки
int input_string(char *s);

// Разбиение строки
int split_array(char *s, char words[][W + 1], size_t *arr_len, char *sep);

// Удаление повторяющихся элементов
void do_uniqe(char arr[][W + 1], size_t *arr_len);

// Вывод
// void print(char arr[][W + 1], int yn[], size_t arr_len);

// Вывод
void yes_or_no(char arr1[][W + 1], char arr2[][W + 1], size_t arr1_len, size_t arr2_len);

#endif
