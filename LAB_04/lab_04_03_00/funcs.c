#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "funcs.h"

int string_input(char *s)
{
    int ch;
    size_t i = 0;
    printf("Введите строку: ");
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < S)
            s[i++] = ch;
        else
            return ERR_IO;
    s[i] = '\0';

    return OK;
}

size_t split(char *s, char arr_words[][W + 1], size_t *arr_len, char *sep)
{
    char *cur_str;
    size_t j = 0;

    cur_str = strtok(s, sep);
    
    while (cur_str)
    {
        if (strlen(cur_str) > W)
            return ERR_PROCESS;
        
        strcpy(arr_words[j], cur_str);
        cur_str = strtok(NULL, sep);
        j++;
    }

    if (j == 0)
        return ERR_PROCESS;

    *arr_len = j;
        
    return OK;
}

void copy_or_remove_letters(char *s, size_t *position, char *word)
{
    char first_letter = word[0];

    s[(*position)++] = first_letter;
    for (size_t i = 1; i < strlen(word); i++)
    {
        if (first_letter == word[i])
            continue;
        s[(*position)++] = word[i];
    }
    s[(*position)++] = ' ';
}

void make_new_string(char *s, char arr_words[][W + 1], size_t arr_len)
{
    size_t p = 0;
    
    for (size_t i = arr_len - 2; i < arr_len; i--)
        if (strcmp(arr_words[arr_len - 1], arr_words[i]) != 0)
            copy_or_remove_letters(s, &p, arr_words[i]);
    s[p] = '\0';
}
