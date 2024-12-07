#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

int main(int argc, char *argv[])
{
    FILE *f;
    double medium = 0.0;
    double sigma = 0.0;
    int rc;

    if (argc != 2)
    {
        printf("Error Args");
        return ERR_EXIST;
    }

    f = fopen(argv[1], "r");
    
    if (!f)
    {
        printf("Error exist");
        return ERR_EXIST;
    }
    
    rc = get_medium(f, &medium);
    if (rc != OK)
    {
        return ERR_CONTENT;
    }
    
    rewind(f);
    
    rc = check_on_eq(f, medium);
    rewind(f);
    
    if (rc != OK)
    {
        printf("%d", OK);
        return OK;
    }
    
    get_sigma(f, medium, &sigma);
    rewind(f);
    
    rc = check(f, medium, sigma);

    fclose(f);
    printf("%d", rc);

    return OK;
}
