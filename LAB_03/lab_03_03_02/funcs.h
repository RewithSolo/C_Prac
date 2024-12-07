#ifndef __FUNCS_H__
#define __FUNCS_H__

#define N 10
#define M 10

#define ERR_RANGE 2
#define ERR_IO 1
#define OK 0

// Ввод матрицы
int input(int arr[][M], size_t *a_n, size_t *a_m);

// Произведение элементов столбца
int mult(int arr[], size_t a_m);

// Смена мест элементов массива между собой
void swap(int arr1[], int arr2[], size_t n);

// Сортировка элементов массива по произведеению чисел в строках
void sort_m(int arr[][M], size_t a_n, size_t a_m);

// Вывод матрицы
void print(int arr[][M], size_t a_n, size_t a_m);

#endif
