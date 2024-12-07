#include <stdio.h>
#include <stdlib.h>

#define N 10

#define OK 0
#define ERR_INPUT 1
#define SIZE_ERROR 2
#define ONE_SIZE 3

// Ввод массива
int input_array(int *pa, int *pb)
{
    for (int *pcur = pa; pcur < pb; pcur++)
        if (scanf("%d", pcur) != 1)
            return ERR_INPUT;
    return OK;
}

// Поиск минимального произведения
int calc_value(int *pa, int *pb, int *res)
{
    int temp = 1;
    int count = 0;
    int min_el = 0;
    if (pa == pb - 1)
        return ONE_SIZE;
    
    for (int *pcur = pa; pcur < pb - 1; pcur++)
    {
        if (count == 0)
        {
            min_el = *pcur * (*(pcur + 1));
            count++;
        }
        temp = *pcur * (*(pcur + 1));
        if (temp < min_el)
            min_el = temp;
    }
    *res = min_el;
    return OK;
}

int main(void)
{
    int arr[N];
    int n;
    int res;
    
    printf("Input size of list: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Error input");
        return ERR_INPUT;
    }
    if (n <= 0 || n > N)
    {
        printf("Error size list");
        return SIZE_ERROR;
    }
    
    int *pa = arr; // Указатель на первый элемент
    int *pb = arr + n; // Указатель на элемент за последним
    
    printf("Input list: \n");
    if (input_array(pa, pb))
        return ERR_INPUT;
    
    int rc = calc_value(pa, pb, &res);
    if (rc == ONE_SIZE)
    {
        printf("List has one element");
        return ONE_SIZE;
    }
    printf("Result: %d\n", res);
    return OK;
}
