#ifndef PRODUCT_H__
#define PRODUCT_H__

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "error.h"
#define TITLE_LEN 25
#define DEVELOPER_LEN 10

struct product_t
{
    char surname[TITLE_LEN + 1];
    char name[DEVELOPER_LEN + 1];
    uint32_t marks[4];
};
int write_student_into_file(FILE *f, struct product_t *product);

int read_student_from_file(FILE *f, struct product_t *product);

int product_read(FILE *f, struct product_t *pp);

#endif
