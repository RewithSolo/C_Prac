#ifndef __FUNCS_H__
#define __FUNCS_H__

#include "errors.h"

#define N 10
#define M 10

// Проверка на четность суммы цифр числа
bool is_sum(int el);

// Создания массива с номерами строк перед которыми нужно вставить массив единиц
int arr_of_id(int matr[][M], size_t rows, size_t columns, size_t arr[], size_t *len);

// Вывод матрицы
void print(int matr[][M], size_t rows, size_t columns);

// Ввод матрицы
int input(int matr[][M], size_t *rows, size_t *columns);

// Вставка строки
void row_insert(int matr[][M], size_t *rows, size_t columns, size_t id);

// Вставка всех строк
void insert(int matr[][M], size_t *rows, size_t columns, size_t arr[], size_t len);

#endif
