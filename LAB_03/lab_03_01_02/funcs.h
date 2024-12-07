#ifndef __FUNCS_H__
#define __FUNCS_H__

#define N 10
#define M 10

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

// Ввод матрицы
int input(int arr[][M], size_t *a_n, size_t *a_m);

// Проверка столбца на чередующиеся положительные и отрицальные числа
bool check(int arr[][M], size_t a_n, size_t k);

// Создание массива с соотвествующими элементами столбцам
void create_arr(int arr[][M], int a[], size_t a_m, size_t a_n);

// Вывод массива
void print_arr(int a[], size_t a_m);

#endif
