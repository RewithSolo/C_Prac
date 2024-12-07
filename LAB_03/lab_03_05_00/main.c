#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

int main()
{
    int arr[N][M];
    int a[SIZE];
    size_t a_n, a_m, s;
    int rc = input(arr, &a_n, &a_m);
    if (rc == ERR_IO)
    {
        printf("Error Input");
        return ERR_IO;
    }
    else if (rc == ERR_RANGE)
    {
        printf("Error Range");
        return ERR_RANGE;
    }
    create_arr(arr, a, a_n, a_m, &s);
    if (s == 0)
    {
        printf("Error exist");
        return ERR_EXIST;
    }
    insert_elements(arr, a, a_n, a_m, s);
    print_matrix(arr, a_n, a_m);
    return OK;
}

