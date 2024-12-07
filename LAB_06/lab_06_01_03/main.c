#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "product_array.h"
#include "error.h"

int main(int argc, char **argv)
{
    int rc = ERR_OK;
    int rcd = ERR_OK;
    FILE *f;
    struct product_t pproducts[N];
    if (argc == 3)
    {
        f = fopen(argv[1], "r");
        char *end_ptr;
        double price_l = strtod(argv[2], &end_ptr);
        size_t n;
        if (f && price_l > 0)
        {
            rc = read_number_of_structs(f, &n);
            
            if (rc == ERR_OK)
                rcd = product_arr_read(f, pproducts, n);
            
            fclose(f);
            if (rc == ERR_OK && rcd == ERR_OK)
                product_arr_check(pproducts, n, price_l);
            else
                rc = ERR_READ;
        }
        else
            rc = ERR_OPEN;
    }
    else
        rc = ERR_ARGS;
    
    return rc;
}
