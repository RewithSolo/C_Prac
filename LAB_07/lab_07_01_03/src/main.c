#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/funcs.h"

int main(int argc, char **argv)
{
    int rc = ERR_OK;
    FILE *f1, *f2;
    size_t count;
    if (argc == 3)
    {
        f1 = fopen(argv[1], "r");
        if (f1)
        {
            rc = count_numbers(f1, &count);
            rewind(f1);
            if (rc == ERR_OK && count > 0)
            {
                int *arr = NULL;
                int *pb_dst = NULL, *pe_dst = NULL;
                arr = malloc(sizeof(int) * count);
                pb_dst = arr;
                pe_dst = pb_dst + count;
                rc = read_numbers(f1, pb_dst, pe_dst);
                fclose(f1);
                if (rc == ERR_OK)
                {
                    mysort(pb_dst, pe_dst - pb_dst, sizeof(int), cmp);
                    f2 = fopen(argv[2], "w");
                    print(f2, pb_dst, pe_dst);
                    fclose(f2);
                    free(arr);
                }
                else
                {
                    rc = ERR_CONTENT;
//                    printf("Ошибка прочтения данных файла.\n");
                    free(arr);
                }
            }
            else
            {
                rc = ERR_READ;
//                printf("Ошибка прочтения файла.\n");
                fclose(f1);
            }
        }
        else
            rc = ERR_OPEN;
    }
    else if (argc == 4)
    {
        f1 = fopen(argv[1], "r");
        if (f1 && strcmp(argv[3], "f") == 0)
        {
            rc = count_numbers(f1, &count);
            rewind(f1);
            if (rc == ERR_OK)
            {
                int *arr = NULL;
                int *pb_dst = NULL, *pe_dst = NULL;
                int *pb_filt = NULL, *pe_filt = NULL;
                arr = malloc(sizeof(int) * count);
                pb_dst = arr;
                pe_dst = pb_dst + count;
                rc = read_numbers(f1, pb_dst, pe_dst);
                fclose(f1);
                if (rc == ERR_OK && arr != NULL)
                {
                    rc = key(arr, arr + count, &pb_filt, &pe_filt);
                    if (rc == ERR_OK)
                    {
                        mysort(pb_filt, pe_filt - pb_filt, sizeof(int), cmp);
                        f2 = fopen(argv[2], "w");
                        print(f2, pb_filt, pe_filt);
                        fclose(f2);
                        free(arr);
                        free(pb_filt);
                    }
                    else
                    {
                        rc = ERR_PROCESS;
 //                       printf("Ошибка обработки файла.\n");
                        free(arr);
                        free(pb_filt);
                    }
                }
                else
                {
                    rc = ERR_CONTENT;
//                    printf("Ошибка прочтения данных файла.\n");
                    free(arr);
                }
            }
            else
            {
                rc = ERR_READ;
//                printf("Ошибка прочтения файла.\n");
                fclose(f1);
            }
        }
        else
        {
//            printf("Ошибка открытия файла.\n");
            rc = ERR_OPEN;
        }
    }
    else
    {
//        printf("Неверное количество аргументов строки.\n");
        rc = ERR_ARGS;
    }
    return rc;
}
