#ifndef __FUNCS_H__
#define __FUNCS_H__

#define N 10
#define M 10

#define ERR_EXIST 3
#define ERR_RANGE 2
#define ERR_IO 1
#define OK 0

// Проверка существования числа заканчивающегося на 5 под нижней диагональю
bool check_inp(int arr[][M], size_t a_n, int *max_el);

// Ввод матрицы
int input(int arr[][M], size_t *a_n);

// Поиск максимального элемента заканчевающегося на 5 под нижней диагональю
void max_elem(int arr[][M], size_t a_n, int *max_el);

#endif
