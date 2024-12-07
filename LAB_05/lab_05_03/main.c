#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "funcs.h"

int main(int argc, char **argv)
{
    FILE *f;
    int rc;
    char *end_ptr;
    size_t count_nums;
    
    if (argc == 4)
    {
        if (!strcmp(argv[1], "c"))
        {
            count_nums = strtol(argv[2], &end_ptr, 10);
            if (!(*end_ptr))
            {
                f = fopen(argv[3], "wb");
                if (f)
                {
                    rc = create_bin_file(f, count_nums);
                    fclose(f);
                }
                else
                    rc = ERR_ARGS;
            }
            else
                rc = ERR_ARGS;
        }
        else
            rc = ERR_ARGS;
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "p") == 0)
        {
            f = fopen(argv[2], "rb");
            rc = check(argv[2]);
            
            if (f && rc == OK)
            {
                rc = print_file(f);
                fclose(f);
            }
            else
                rc = ERR_ARGS;
        }
        else if (strcmp(argv[1], "s") == 0)
        {
            f = fopen(argv[2], "rb+");
            rc = check(argv[2]);
            if (f && rc == OK)
            {
                rc = sort_file(f);
                fclose(f);
            }
            else
                rc = ERR_ARGS;
        }
        else
            rc = ERR_ARGS;
    }
    else
        rc = ERR_ARGS;
    
    return rc;
}

