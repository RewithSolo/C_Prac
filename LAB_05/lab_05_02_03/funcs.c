#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

int get_medium(FILE *f, double *medium)
{
    double cur;
    double med = 0.0;
    size_t count = 0;
    while (fscanf(f, "%lf", &cur) == 1)
    {
        med += cur;
        count++;
    }
    if (count == 0)
        return ERR_CONTENT;

    med = med / count;
    *medium = med;
    return OK;
}

int check_on_eq(FILE *f, double medium)
{
    double cur;
    while (fscanf(f, "%lf", &cur) == 1)
        if (abs(cur - medium) > EPS)
            return OK;

    return ERR_EXIST;
}

void get_sigma(FILE *f, double medium, double *sigma)
{
    double cur = 0;
    double sigm = 0;
    size_t count = 0;
    while (fscanf(f, "%lf", &cur) == 1)
    {
        sigm += (cur - medium) * (cur - medium);
        count++;
    }
    sigm = sqrt(sigm / (count - 1));
    *sigma = sigm;
}


int check(FILE *f, double medium, double sigma)
{
    double cur;
    while (fscanf(f, "%lf", &cur) == 1)
        if (cur > (medium + 3 * sigma) || cur < (medium - 3 * sigma))
            return 0;
    return 1;
}
