#ifndef __FUNCS_H__
#define __FUNCS_H__
#include "errors.h"

#define S 256
#define W 20
#define M 12

// Ввод строки
int input_string(char *s);

// int mask_check(char *s);

// Разбиение строки на массив
// size_t split_array(char *s, char words[][W + 1], size_t *arr_len, char *sep);

// Проверка строки на валидность
// int check(char arr[][W + 1], size_t arr_len, char *months[]);

bool check(const char *s, char *months[]);

#endif
