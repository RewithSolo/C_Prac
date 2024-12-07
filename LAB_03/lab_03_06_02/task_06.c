#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(void)
{
    int arr[N][M];
    size_t a_n, a_m;
    
    int rc = input_matrix(&a_n, &a_m);
    if (rc == ERR_IO)
    {
        printf("Error IO");
        return ERR_IO;
    }
    else if (rc == ERR_RANGE)
    {
        printf("Error Range");
        return ERR_RANGE;
    }
    
    fill(arr, a_n, a_m);
    print(arr, a_n, a_m);
    return OK;
}
