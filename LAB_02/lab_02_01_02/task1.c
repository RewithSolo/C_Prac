#include <stdio.h>
#include <stdbool.h>

#define OK 0
#define ERR_IO 1
#define ERR_SIZE 2
#define ERR_EXST 3
#define N 10

// Функция проверки, что в массиве есть хотя бы 1 отрицательное число
// bool is_negative(int a[], size_t n)
// {
//    for (size_t i = 0; i < n; ++i)
//        if (a[i] < 0)
//            return 1;
//
//    return 0;
// }

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

// Функция подсчета среднего арифметического
int calc_res(const int a[], size_t n, double *res)
{
    int count = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (a[i] < 0)
        {
            *res += a[i];
            count++;
        }
    }
    if (count == 0)
        return ERR_EXST;
    *res = *res / (count * 1.0);

    return OK;
}


int main(void)
{
    size_t n;
    double res = 0.0;
    int a[N];
    int rc = input(a, &n);
    if (rc == ERR_IO)
    {
        printf("IO Error");
        return ERR_IO;
    }
    else if (rc == ERR_SIZE)
    {
        printf("Size Error");
        return ERR_IO;
    }

    rc = calc_res(a, n, &res);
    if (rc == ERR_EXST)
    {
        printf("IO Error. You need to input negative num");
        return ERR_EXST;
    }
    printf("Result: %lf\n", res);
    return OK;
}
