#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcs.h"

int main(void)
{
    size_t rows, columns;
    size_t len = 0;
    size_t arr[2 * N];
    
    int matr[N * 2][M];

    int rc = input(matr, &rows, &columns);
    if (rc == ERR_IO)
    {
        printf("ERROR IO\n");
        return ERR_IO;
    }
    else if (rc == ERR_RANGE)
    {
        printf("ERROR RANGE\n");
        return ERR_RANGE;
    }

    arr_of_id(matr, rows, columns, arr, &len);

    if (len != 0)
        insert(matr, &rows, columns, arr, len);

    print(matr, rows, columns);
    
    return OK;
}
