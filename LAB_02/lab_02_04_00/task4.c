#include <stdio.h>
#include <stdbool.h>
#define OK 0
#define ERR_IO 1
#define BEFORE 100
#define N 10

// Функция ввода значений
int input(int a[], size_t *n)
{
    size_t i = 0;
    int cur_num;
    printf("Input while not num: ");
    while (scanf("%d", &cur_num) == 1)
    {
        if (i == N)
        {
            *n = i;
            return BEFORE;
        }
        a[i] = cur_num;
        i++;
    }
    *n = i;
    if (i == 0)
        return ERR_IO;
    
    return OK;
}

// Функция сортировки пузырьком
// void bubble_sort(int a[], size_t n)
// {
//    int tmp;
//
//    for (size_t i = 0; i < n; i++)
//    {
//        for (size_t j = 0; j < n - i - 1; j++)
//        {
//            if (a[j] > a[j + 1])
//            {
//                tmp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = tmp;
//            }
//        }
//    }
// }

void selection_sort(int a[], size_t n)
{
    int min_el;
    size_t min_ind;
    int tmp;
    for (size_t i = 0; i < n; i++)
    {
        min_el = a[i];
        min_ind = i;
        for (size_t j = i; j < n; j++)
            if (a[j] < min_el)
            {
                min_el = a[j];
                min_ind = j;
            }
        tmp = a[i];
        a[i] = a[min_ind];
        a[min_ind] = tmp;
    }
}

// Функция выводит массив
void print(int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    size_t n;
    int a[N];
    int rc = input(a, &n);
    if (rc == ERR_IO)
    {
        printf("Error input");
        return ERR_IO;
    }
    
    selection_sort(a, n);
    print(a, n);
    if (rc == BEFORE)
    {
        printf("Error overflow");
        return BEFORE;
    }

    return OK;
}
