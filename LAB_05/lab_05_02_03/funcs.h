#ifndef __FUNCS_H__
#define __FUNCS_H__

#define OK 0
#define ERR_CONTENT 1
#define ERR_EXIST 2

#define EPS 0.00001

int file_check(char name[]);

int get_medium(FILE *f, double *medium);

int check_on_eq(FILE *f, double medium);

void get_sigma(FILE *f, double medium, double *sigma);

int check(FILE *f, double medium, double sigma);

#endif
