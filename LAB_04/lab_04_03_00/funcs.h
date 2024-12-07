#ifndef __FUNCS_H__
#define __FUNCS_H__
#include "errors.h"

#define S 256
#define W 20

// Ввод строки
int string_input(char *s);

// Разбиение строки
size_t split(char *s, char arr_words[][W + 1], size_t *arr_len, char *sep);

// Копирование или удаление букв
void copy_or_remove_letters(char *s, size_t *position, char *word);

// Создание новой строки
void make_new_string(char *s, char arr_words[][W + 1], size_t arr_len);

#endif
