#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

bool check_for_simply(int num)
{
    int count = 0;
    int numie = num;
    
    if (numie <= 0)
        return false;
    
    for (int i = 1; i < (numie / 2) + 1; i++)
        if (numie % i == 0)
            count++;
    
    if (count > 1)
        return false;
    
    return true;
}

int input(int arr[][M], size_t *a_n, size_t *a_m)
{
    size_t rows;
    size_t columns;
    int cur = 0;
    printf("Enter size of array: rows and columns >>> ");
    if (scanf("%zu %zu", &rows, &columns) != 2)
        return ERR_IO;
    else if (rows > N || columns > M)
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

void create_arr(int arr[][M], int a[], size_t a_n, size_t a_m, size_t *s)
{
    size_t k = 0;
    for (size_t i = 0; i < a_n; i++)
        for (size_t j = 0; j < a_m; j++)
            if (check_for_simply(arr[i][j]))
            {
                a[k] = arr[i][j];
                k++;
            }
    
    *s = k;
}

void insert_elements(int arr[][M], int a[], size_t a_n, size_t a_m, size_t s)
{
    size_t k = s - 1;
    for (size_t i = 0; i < a_n; i++)
        for (size_t j = 0; j < a_m; j++)
            if (check_for_simply(arr[i][j]))
            {
                arr[i][j] = a[k];
                k--;
            }
}

void print_matrix(int arr[][M], size_t a_n, size_t a_m)
{
    printf("Output array: \n");
    for (size_t i = 0; i < a_n; i++)
    {
        for (size_t j = 0; j < a_m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    
    printf("\n");
}
