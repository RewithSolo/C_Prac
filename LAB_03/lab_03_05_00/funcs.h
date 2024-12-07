#ifndef __HEAD_H__
#define __HEAD_H__

#include "errors.h"
#define N 10
#define M 10
#define SIZE 100

// Ввод матрицы
int input(int arr[][M], size_t *a_n, size_t *a_m);

// Проверка на простоту
bool check_for_simply(int num);

// Создание массива из простых чисел
void create_arr(int arr[][M], int a[], size_t a_n, size_t a_m, size_t *s);

// Вставка элементов в обратном порядке
void insert_elements(int arr[][M], int a[], size_t a_n, size_t a_m, size_t s);

// Вывод матрицы
void print_matrix(int arr[][M], size_t a_n, size_t a_m);

#endif
