#ifndef PRODUCT_H__
#define PRODUCT_H__
#include "error.h"
#define TITLE_LEN 25
#define N 15

// Структура описывающая продукт, как набор полей имени и цены
struct product_t
{
    char title[TITLE_LEN + 1];
    int price;
};

// Чтение структуры из файла
int product_read(FILE *f, struct product_t *pp);


// Вывод структуры и сравнение  на экран
void product_print(const struct product_t pp);

#endif
