#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/funcs.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (!pb_src || !pe_src)
        return ERR_NULL_POINTER;

    if (pb_src > pe_src)
        return ERR_RANGE;

    int count = 0;
    int const *ptr = pb_src, *p_min = pe_src;
    
    while (ptr < pe_src)
    {
        if (*ptr < 0)
            p_min = ptr;

        ptr++;
    }
    
    ptr = pb_src;
    
    while (ptr < p_min)
    {
        count++;
        ptr++;
    }
    if (!count)
        return ERR_RANGE_RES;
    
    *pb_dst = malloc(sizeof(int) * count);
    *pe_dst = *pb_dst + count;
    memcpy(*pb_dst, pb_src, count * sizeof(int));
/*    
    int *pb = *pb_dst;
    ptr = pb_src;
    
    while (ptr < p_min)
    {
        *pb = *ptr;
        pb++;
        ptr++;
    }
*/    
    return ERR_OK;
}

int cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

void swap(char *a, char *b, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        char temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void mysort(void *beg, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    char *bp = beg;
    for (int i = count - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
            if (comp(bp + j * size, bp + (j + 1) * size) > 0)
                swap(bp + j * size, bp + (j + 1) * size, size);
    }
}

int count_numbers(FILE *f, size_t *count)
{
    int cur;
    size_t count_l = 0;
    while (fscanf(f, "%d", &cur) == 1)
        count_l++;
    if (count_l == 0)
        return ERR_RANGE;
        
    *count = count_l;
    return ERR_OK;
}

void print(FILE *f, int *pb_dst, int *pe_dst)
{
    int *ptr = pb_dst;

    while (ptr < pe_dst)
    {
        fprintf(f, "%d ", *ptr);
        ptr++;
    }
}

int read_numbers(FILE *f, int *ps, int *pe)
{
    int num = 0;
    for (; ps < pe; ps++)
        if (fscanf(f, "%d", &num) == 1)
            *ps = num;
        else
            return ERR_CONTENT;
    
    return ERR_OK;
}
