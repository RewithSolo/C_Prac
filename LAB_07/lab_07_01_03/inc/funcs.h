#ifndef FUNCS_H__
#define FUNCS_H__

#include "error.h"
#include <stdlib.h>
#include <stdio.h>

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

int cmp(const void *a, const void *b);

void swap(char *a, char *b, size_t size);

void mysort(void *beg, size_t count, size_t size, int (*comp)(const void*, const void*));

int count_numbers(FILE *f, size_t *count);

void print(FILE *f, int *pb_dst, int *pe_dst);

int read_numbers(FILE *f, int *ps, int *pe);

#endif
