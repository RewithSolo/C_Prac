#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcs.h"

bool is_sum(int el)
{
    int sum = 0;
    while (el)
    {
        sum += el % 10;
        el /= 10;
    }

    if (sum % 2 != 0)
        return true;
    return false;
}

int arr_of_id(int matr[][M], size_t rows, size_t columns, size_t arr[], size_t *len)
{
    int count;
    for (size_t i = rows - 1; i < rows; i--)
    {
        count = 0;
        for (size_t j = 0; j < columns; j++)
        {
            if (is_sum(matr[i][j]))
                count++;
        }

        if (count >= 2)
        {
            arr[*len] = i;
            (*len)++;
        }
    }

    return OK;
}

void print(int matr[][M], size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            printf("%d ", matr[i][j]);
        printf("\n");
    }
}

int input(int matr[][M], size_t *rows, size_t *columns)
{
    printf("Enter the size of matrix: ");
    if (scanf("%zu %zu", rows, columns) != 2)
        return ERR_IO;
    else if (*rows == 0 || *rows > N || *columns == 0 || *columns > M)
        return ERR_RANGE;
    printf("Enter the elements: ");
    for (size_t i = 0; i < *rows; i++)
        for (size_t j = 0; j < *columns; j++)
            if (scanf("%d", &(matr[i][j])) != 1)
                return ERR_IO;

    return OK;
}

void row_insert(int matr[][M], size_t *rows, size_t columns, size_t id)
{
    for (size_t i = *rows; i > id; i--)
        for (size_t j = 0; j < columns; j++)
            matr[i][j] = matr[i - 1][j];
            
    for (size_t j = 0; j < columns; j++)
        matr[id][j] = -1;

    (*rows)++;
}

void insert(int matr[][M], size_t *rows, size_t columns, size_t arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        row_insert(matr, rows, columns, arr[i]);
}
