#ifndef PRODUCT_ARRAY_H__
#define PRODUCT_ARRAY_H__
#include <stddef.h>
#include "error.h"

#include "product.h"

int read_number_of_structs(FILE *f, size_t *n_max);

int product_arr_read(FILE *f, struct product_t *pproducts, size_t n);

void product_arr_check(const struct product_t *pproducts, size_t n, double price_l);

#endif
