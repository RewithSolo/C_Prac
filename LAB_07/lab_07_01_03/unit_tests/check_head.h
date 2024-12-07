#ifndef CHECK_HEAD_H__
#define CHECK_HEAD_H__

#include <stdlib.h>
#include "../inc/funcs.h"
#include "../inc/error.h"
#include <check.h>

#define OK    0
#define ERROR 1

Suite* filter_array(void);

Suite* sort_array(void);

#endif
