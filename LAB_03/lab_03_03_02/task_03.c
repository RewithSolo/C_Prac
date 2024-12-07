#include <stdio.h>
#include "funcs.h"

int main()
{
    int arr[N][M];
    size_t a_n, a_m;
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
    sort_m(arr, a_n, a_m);
    print(arr, a_n, a_m);
    return OK;
}
