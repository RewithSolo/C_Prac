#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "funcs.h"

bool check_inp(int arr[][M], size_t a_n, int *max_el)
{
    for (size_t i = 0; i < a_n; i++)
    {
        for (size_t j = a_n - i; j < a_n; j++)
        {
            if (abs(arr[i][j]) % 10 == 5)
            {
                *max_el = arr[i][j];
                return true;
            }
        }
    }
    return false;
}
int input(int arr[][M], size_t *a_n)
{
    size_t rows;
    size_t columns;
    int cur = 0;
    printf("Enter size of square matrix >>> ");
    if (scanf("%zu %zu", &rows, &columns) != 2)
        return ERR_IO;
    else if (rows > N || rows == 0 || columns > N || columns == 0 || rows != columns)
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
    return OK;
}

void max_elem(int arr[][M], size_t a_n, int *max_el)
{
    for (size_t i = 0; i < a_n; i++)
    {
        for (size_t j = a_n - i; j < a_n; j++)
        {
            if (arr[i][j] > *max_el && abs(arr[i][j]) % 10 == 5)
                *max_el = arr[i][j];
        }
    }
}
