#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define OK 0
#define ERR_IO 1
#define ERR_SIZE 2
#define ERR_EXST 3
#define N 10

// Функция определяет, равны ли её первая и последняя цифры
bool is_equ(int num)
{
    int last, first;
    last = abs(num % 10);
    for (first = abs(num); first >= 10; first = first / 10);
    if (last == first)
    {
        return true;
    }
    return false;
}

// Функция проверки, что в массиве есть хотя бы 1 элемент у которого первая и последняя цифры одинаковые
bool is_in_arr(const int a[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
        if (is_equ(a[i]))
            return 1;

    return 0;
}

// Функция ввода значений
int input(int a[], size_t *n)
{
    printf("Input size: ");
    if (scanf("%zu", n) != 1)
        return ERR_IO;
    if (*n <= 0 || *n > N)
        return ERR_SIZE;

    for (size_t i = 0; i < *n; ++i)
        if (scanf("%d", &a[i]) != 1)
            return ERR_IO;

    return OK;
}

// Функция записывает нужные числа в новый массив
void copy(const int a[], size_t n, int *new_a, size_t *new_n)
{
    size_t j;
    j = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (is_equ(a[i]))
        {
            new_a[j] = a[i];
            j++;
        }
    }
    *new_n = j;
}

// Функция выводит массив
void print(const int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Главная функция
int main(void)
{
    size_t n, new_n;
    int a[N];
    int new_a[N];
    int rc = input(a, &n);
    if (rc == ERR_IO)
    {
        printf("IO Error");
        return rc;
    }
    else if (rc == ERR_SIZE)
    {
        printf("Size Error");
        return rc;
    }

    if (!is_in_arr(a, n))
    {
        printf("IO Error. You need to input num which first and second equal");
        return ERR_EXST;
    }
    
    copy(a, n, new_a, &new_n);
    print(new_a, new_n);
    return OK;
}

