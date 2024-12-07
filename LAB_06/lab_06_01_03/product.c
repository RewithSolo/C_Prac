#include <stdio.h>
#include <string.h>
#include "product.h"

int product_read(FILE *f, struct product_t *pp)
{
	char buf_title[TITLE_LEN + 2];
	size_t len;
	char tmp[8];
	int price;
	
	if (!fgets(buf_title, sizeof(buf_title), f))
		return ERR_PROCESS;

	len = strlen(buf_title);
	
	if (len && buf_title[len - 1] == '\n')
	{
		buf_title[len - 1] = '\0';
		len--;
	}
	
	if (!len || len > TITLE_LEN)
		return ERR_PROCESS;
	
	if (fscanf(f, "%d", &price) != 1)
		return ERR_PROCESS;
	
	if (price <= 0)
		return ERR_PROCESS;
	
	fgets(tmp, sizeof(tmp), f);
	strcpy(pp->title, buf_title);
	pp->price = price;
	
	return ERR_OK;
}

void product_print(const struct product_t pp)
{
	printf("%s\n%d\n", pp.title, pp.price);
}
