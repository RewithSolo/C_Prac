#include <stdio.h>
#include "product_array.h"
#include "product.h"

int read_number_of_structs(FILE *f, size_t *n_max)
{
	int rc = ERR_OK;
	
	if (fscanf(f, "%zu\n", n_max) != 1)
		rc = ERR_PROCESS;
	else if (*n_max > N || *n_max < 1)
		rc = ERR_RANGE;
	
	return rc;
}

int product_arr_read(FILE *f, struct product_t *pproducts, size_t n)
{
	struct product_t product;
	size_t i = 0;
	int rc = ERR_OK;
	while (rc == ERR_OK)
	{
		rc = product_read(f, &product);
		if (rc == ERR_OK)
		{
			if (i < N)
			{
				pproducts[i] = product;
				i++;
			}
			else
				rc = ERR_PROCESS;
		}
	}
	
	if (feof(f))
		rc = ERR_OK;
	
	if (i != n)
		rc = ERR_PROCESS;
	
	return rc;
}

void product_arr_check(const struct product_t *pproducts, size_t n, double price_l)
{	
	for (size_t i = 0; i < n; i++)
		if ((double)pproducts[i].price < price_l)
			product_print(pproducts[i]);
}

