#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int input_string(char *s)
{
    printf("Введите строку: ");
    if (!fgets(s, S + 1, stdin))
        return ERR_IO;

    char *c = strchr(s, '\n');
    if (!c)
        return ERR_IO;

    s[strlen(s) - 1] = '\0';

/*    for (size_t i = 0; i < strlen(s); i++)
        if (isspace(s[i]))
            s[i] = ' ';*/

    return OK;
}

int split_array(char *s, char words[][W + 1], size_t *arr_len, char *sep)
{
    size_t j = 0;
    size_t z = 0;

    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if (strchr(sep, s[i]) == NULL)
        {
            words[j][z++] = s[i];
            if (z > W)
                return ERR_PROCESS;
        }
        else
        {
            if (z != 0)
            {
                words[j++][z] = '\0';
                z = 0;
            }
        }
    }
    if (z != 0)
        words[j++][z] = '\0';
    if (j == 0)
        return ERR_PROCESS;
    *arr_len = j;

    return OK;
}

void do_uniqe(char arr[][W + 1], size_t *arr_len)
{
    size_t len = *arr_len;
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = i + 1; j < len; j++)
        {
            if (strcmp(arr[j], arr[i]) == 0)
            {
                for (size_t k = j; k < len - 1; k++)
                    strcpy(arr[k], arr[k + 1]);
                len--;
                j--;
            }
        }
    }
    *arr_len = len;
}

/* void print(char arr[][W + 1], int yn[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; i++)
    {
        if (yn[i])
            printf("%s yes\n", arr[i]);
        else
            printf("%s no\n", arr[i]);
    }
}
*/


void yes_or_no(char arr1[][W + 1], char arr2[][W + 1], size_t arr1_len, size_t arr2_len)
{
    size_t flag;
    for (size_t i = 0; i < arr1_len; i++)
    {
        flag = 0;
        for (size_t j = 0; j < arr2_len; j++)
        {
            if (strcmp(arr1[i], arr2[j]) == 0 && flag == 0)
            {
                printf("%s yes\n", arr1[i]);
                flag = 1;
            }
        }
        if (!flag)
            printf("%s no\n", arr1[i]);    
    }
}
