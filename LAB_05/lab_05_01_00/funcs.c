#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

int calculate(FILE *f, int *max_element)
{
    int cur = 0;
    int prev = 0;
    int max_el = 0;
    int flag = 0;
    printf("Введите значения: ");
    if (fscanf(f, "%d", &cur) != 1)
        return ERR_IO;
    prev = cur;
    
    while (fscanf(f, "%d", &cur) == 1)
    {
        if (cur > 0 && prev < 0 && cur > max_el)
        {
            flag = 1;
            max_el = cur;
        }
        prev = cur;
    }
    if (!flag)
        return ERR_IO;
    *max_element = max_el;
    return OK;
}

