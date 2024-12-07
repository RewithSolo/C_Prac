#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

int main(void)
{
    int max_element;
    
    int rc = calculate(stdin, &max_element);
    if (rc != OK)
    {
        printf("ERROR process");
        return rc;
    }
    
    printf("%d\n", max_element);

    return OK;
}
