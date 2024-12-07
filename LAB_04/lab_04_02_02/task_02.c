#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main(void)
{
    char sep[] = " ,;:-.!?";
    char s1[S + 1];
    char s2[S + 1];
    int rc = input_string(s1);
    if (rc != OK)
        return rc;
    
    rc = input_string(s2);
    if (rc != OK)
        return rc;

    size_t arr1_len;
    char arr1[S / 2 + 1][W + 1];
    rc = split_array(s1, arr1, &arr1_len, sep);
    if (rc != OK)
        return rc;

    do_uniqe(arr1, &arr1_len);
    size_t arr2_len;
    char arr2[S / 2 + 1][W + 1];
    rc = split_array(s2, arr2, &arr2_len, sep);
    if (rc != OK)
        return rc;

    printf("Result: ");
    yes_or_no(arr1, arr2, arr1_len, arr2_len);
    return OK;
}
