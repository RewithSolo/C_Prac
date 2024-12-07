#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "product.h"
#include "funcs.h"
#include "error.h"

int main(int argc, char **argv)
{
	if (argc < 3)
		return ERR_ARGS;
	FILE *f;
	FILE *newf;
	
	if (strcmp(argv[1], "ft") == 0)
	{	
		if (argc != 5)
			return ERR_ARGS;

		f = fopen(argv[2], "r");
		if (!f)
			return ERR_PROCESS;
		struct product_t pproducts[PRODUCT_COUNT];    
		size_t n;
		int rc = product_arr_read(f, pproducts, &n);
		if (rc != ERR_OK)
			return ERR_PROCESS;
		fclose(f);
		newf = fopen(argv[3], "w");
		char *sub = argv[4];
		rc = print_end(newf, pproducts, n, sub);
		if (rc != ERR_OK)
			return ERR_EXIST;
		fclose(newf);
	}
/*	else if (strcmp(argv[1], "db") == 0)
	{
		f = fopen(argv[2], "r");
		if (!f)
			return ERR_PROCESS;
		newf = fopen(argv[3], "w");
		if (!newf)
			return ERR_PROCESS;
		struct product_t pproducts[PRODUCT_COUNT];    
		size_t n;
		int rc = product_arr_read(f, pproducts, &n);
		if (rc != ERR_OK)
			return ERR_PROCESS;
//		product_sort(newf, pproducts, n);
		fclose(f);
	}
*/
	else if (strcmp(argv[1], "db") == 0)
	{
		if (argc != 3)
			return ERR_ARGS;
		
		f = fopen(argv[2], "rb+");
		if (!f)
			return ERR_PROCESS;
		size_t n = 0;
/*		struct product_t pproducts[PRODUCT_COUNT];    
		
		int rc = product_arr_read(f, pproducts, &n);
		if (rc != ERR_OK)
			return ERR_PROCESS;
		
		fclose(f);
		f = fopen(argv[2], "wb");
		rc = delete_stud(f, pproducts, n);*/
		int rc = filter_students(f, &n);
		if (rc != ERR_OK)
			return ERR_PROCESS;
		truncate(argv[2], n * sizeof(struct product_t));
		fclose(f);
	}
	else
		return 53;
	return ERR_OK;
}
