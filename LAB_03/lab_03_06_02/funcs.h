#ifndef __HEAD_H__
#define __HEAD_H__

#include "errors.h"
#define N 10
#define M 10

// Заполнение матрицы
void fill(int arr[][M], size_t a_n, size_t a_m);

// Ввод размера матрицы
int input_matrix(size_t *a_n, size_t *a_m);

// Вывод матрицы
void print(int arr[][M], size_t a_n, size_t a_m);

#endif
