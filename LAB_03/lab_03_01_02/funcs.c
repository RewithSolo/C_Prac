#include <stdio.h>
#include <stdbool.h>
#include "funcs.h"

int input(int arr[][M], size_t *a_n, size_t *a_m)
{
    size_t rows;
    size_t columns;
    int cur = 0;
    printf("Enter size of array: rows and columns >>> ");
    if (scanf("%zu %zu", &rows, &columns) != 2)
        return ERR_IO;
    else if (rows > N || columns > M || rows == 0 || columns == 0)
        return ERR_RANGE;
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Enter element >>> ");
            if (scanf("%d", &cur) != 1)
                return ERR_IO;
            arr[i][j] = cur;
        }
    }
    *a_n = rows;
    *a_m = columns;
    return OK;
}
bool check(int arr[][M], size_t a_n, size_t k)
{
    if (a_n == 1)
        return false;
    for (size_t j = 1; j < a_n; j++)
    {
        if (arr[j][k] * arr[j - 1][k] >= 0)
            return false;
    }
    return true;
}
void create_arr(int arr[][M], int a[], size_t a_m, size_t a_n)
{
    for (size_t k = 0; k < a_m; k++)
        if (check(arr, a_n, k))
        {
            a[k] = 1;
        }
        else
        {
            a[k] = 0;
        }
}
void print_arr(int a[], size_t a_m)
{
    for (size_t i = 0; i < a_m; i++)
        printf("%d ", a[i]);
    printf("\n");
}


