#include <stdio.h>
#include <stdint.h>
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

// Функция для вывода четырехбайтного сдвинутого числа влево
void print_four_byte_num(uint32_t shifted)
{
    for (int i = 31; i >= 0; i--)
    {
        uint32_t bit = shifted >> i;
        printf("%u", bit & 1);
    }
}

// Циклический побитовый сдвиг
uint32_t shift(uint32_t a, int n)
{
    for (int i = 0; i < n; i++)
        a = (a << 1) | (a >> 31);
    return a;
}

// Главная функция
int main()
{
    uint32_t a, shifted;
    int n;

    printf("Enter the a and n: ");
    if (scanf("%u %d", &a, &n) != 2)
    {
        printf("Error: Input ERROR!");
        return ERR_IO;
    }
    else if (n < 0)
    {
        printf("Error: Number n is negative!");
        return ERR_RANGE;
    }
    
//  shifted = (a << n) | (a >> (32 - n));
    shifted = shift(a, n);
    printf("Result: ");
    print_four_byte_num(shifted);
    printf("\n");

    return OK;
}

