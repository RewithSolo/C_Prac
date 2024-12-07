#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "funcs.h"

int main(void)
{
    char sep[] = " ,;:-.!?";
    char s[S + 1];

    if (string_input(s) != OK)
        return ERR_IO;

    char arr_words[S / 2 + 1][W + 1];
    size_t arr_len;

    if (split(s, arr_words, &arr_len, sep) != OK)
        return ERR_PROCESS;

    char new_s[S + 1];

    make_new_string(new_s, arr_words, arr_len);

    if (strlen(new_s) == 0)
        return ERR_PROCESS;
    
    printf("Result: %s\n", new_s);

    return OK;
}
