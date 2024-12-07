#include <stdio.h>
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
            printf("Enter element (%zu-%zu) >>> ", i + 1, j + 1);
            if (scanf("%d", &cur) != 1)
                return ERR_IO;
            arr[i][j] = cur;
        }
    }
    *a_n = rows;
    *a_m = columns;
    return OK; 
}
int mult(int arr[], size_t a_m)
{
    int mult = 1;
    for (size_t j = 0; j < a_m; j++)
    {
        mult *= arr[j];
    }
    return mult;
}
void swap(int arr1[], int arr2[], size_t n)
{
    int tmp;
    for (size_t i = 0; i < n; ++i)
    {
        tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
}

void sort_m(int arr[][M], size_t a_n, size_t a_m)
{
    for (size_t i = 0; i < a_n - 1; i++)
        for (size_t j = 0; j < a_n - 1 - i; j++)
            if (mult(arr[j], a_m) > mult(arr[j + 1], a_m))
                swap(arr[j], arr[j + 1], a_m);
}

void print(int arr[][M], size_t a_n, size_t a_m)
{
    int cur = 0;
    for (size_t i = 0; i < a_n; i++)
    {
        for (size_t j = 0; j < a_m; j++)
        {
            cur = arr[i][j];
            printf("%d ", cur);
        }
        printf("\n");
    }
}


