#ifndef FUNCS_H__
#define FUNCS_H__
#include <stddef.h>
#include "error.h"
#include "product.h"

#define PRODUCT_COUNT 30

void swap_students(FILE *f, size_t index1, size_t index2, struct product_t *product1, struct product_t *product2);

int average_all(FILE *f, double *average);

int filter_students(FILE *f, size_t *size);

int get_student_by_pos(FILE *f, size_t index, struct product_t *product);

int put_student_by_pos(FILE *f, size_t index, struct product_t *product);

double average_local(struct product_t product);

int product_arr_read(FILE *f, struct product_t *pproducts, size_t *n);

void product_print(const struct product_t *pproducts, size_t n);

// void product_sort(FILE *newf, struct product_t *pproducts, size_t n);

// int add_product(FILE *f, struct product_t *pproducts, size_t n);

int delete_stud(FILE *f, struct product_t *pproducts, size_t n);

int print_end(FILE *f, struct product_t *pproducts, size_t n, char *sub);

#endif
