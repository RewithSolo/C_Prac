#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define OK 0
#define ERR_IO 1
#define ERR_SIZE 2
#define ERR_EXST 3
#define ERR_RANGE 4
#define N 10

// Функция определяет, является ли число полным квадратом
// Функция проверяет число по свойству сумм нечетных чисел
// Если при вычитании нечетных чисел в диапазоне от 0 до числа a, из самого числа a,
// Получится ноль, то число является полным квадратом, в обратном случае
// Не является
bool is_full(int a)
{
    int i = 1;
    while (a > 0)
    {
        a -= i;
        i += 2;
    }

    if (a != 0)
        return false;

    return true;
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
    {
        if (scanf("%d", &a[i]) != 1)
        {
            return ERR_IO;
        }
        else if (a[i] < 0)
        {
            return ERR_RANGE;
        }
    }    
    return OK;
}

// Функция удаляет числа, которые являются полными квадратами
int delete_full(int a[], size_t *n)
{
    size_t j = 0;
    for (size_t i = 0; i < *n; i++)
    {
        if (!is_full(a[i]))
        {
            a[j] = a[i];
            j++;
        }
    }
    *n = j;
    return OK;
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

// Главная функция
int main(void)
{
    size_t n;
    int a[N];
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
    else if (rc == ERR_RANGE)
    {
        printf("Error Range");
        return rc;
    }
    delete_full(a, &n);
    if (n == 0)
    {
        printf("List is empty");
        return ERR_EXST;
    }
    print(a, n);
    return OK;
}


