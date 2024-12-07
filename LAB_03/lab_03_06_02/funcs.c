#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void fill(int arr[][M], size_t a_n, size_t a_m)
{
    size_t i = 0;
    int counter = 0;


    while (i < a_m)
    {
        for (size_t j = 0; j < a_n; j++)
        {
            counter++;
            arr[a_n - j - 1][a_m - i - 1] = counter;
        }
        i++;

        if (i >= a_m)
            break;
        
        for (size_t j = 0; j < a_n; j++)
        {
            counter++;
            arr[j][a_m - i - 1] = counter;
        }
        i++;
    }
}

int input_matrix(size_t *a_n, size_t *a_m)
{
    size_t rows, columns;
    printf("Enter the rows and columns >> ");
    if (scanf("%zu %zu", &rows, &columns) != 2)
        return ERR_IO;
    else if (rows == 0 || rows > N || columns == 0 || columns > M)
        return ERR_RANGE;
    
    *a_n = rows;
    *a_m = columns;
    return OK;
}

void print(int arr[][M], size_t a_n, size_t a_m)
{
    for (size_t i = 0; i < a_n; i++)
    {
        for (size_t j = 0; j < a_m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
