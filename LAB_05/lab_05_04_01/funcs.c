#include <stdio.h>
#include "funcs.h"
#include "product.h"
#include <math.h>

#define EPS 0.00001	

void swap_students(FILE *f, size_t index1, size_t index2, struct product_t *product1, struct product_t *product2)
{
	put_student_by_pos(f, index1, product2);
	put_student_by_pos(f, index2, product1);
}

int average_all(FILE *f, double *average)
{
	struct product_t product;
	double sum = 0;
	int quantity = 0;
	int tec = read_student_from_file(f, &product);

	while (tec == ERR_OK && !feof(f))
	{
		sum += product.marks[0];
		sum += product.marks[1];
		sum += product.marks[2];
		sum += product.marks[3];
		quantity += 4;

		tec = read_student_from_file(f, &product);
	}

	*average = sum / quantity;
	if (tec != ERR_OK && feof(f))
		tec = ERR_OK;

	fseek(f, 0, SEEK_SET);

	return tec;
}

int filter_students(FILE *f, size_t *size)
{
	size_t i = 0;
	struct product_t product1, product2;
	int tec;
	double average;
	double tmp1_local; 
	double tmp2_local;

	tec = average_all(f, &average);
	if (tec != ERR_OK)
		return tec;

	tec = get_student_by_pos(f, 0, &product1);

	tmp1_local = average_local(product1);
	if (tmp1_local > average || fabs(tmp1_local - average) < EPS)
		(*size)++;

	while (tec == ERR_OK && !feof(f))
	{      
		if (i == 0 || tmp1_local < average)
		{
			product2 = product1;
			tmp2_local = tmp1_local;
			i++;
		}
		else if (((tmp1_local > average || fabs(tmp1_local - average) < EPS) && tmp2_local < average))
		{
			swap_students(f, i, i - 1, &product1, &product2);
			if (i != 1)
				i--;
			else
				(*size)++;
			get_student_by_pos(f, i - 1, &product2);
			tmp2_local = average_local(product2);   
		}
		else
		{
			(*size)++;
			product2 = product1;
			tmp2_local = tmp1_local;
			i++;  
		}
		tec = get_student_by_pos(f, i, &product1);
		tmp1_local = average_local(product1);
	}
	if (tec != ERR_OK && feof(f))
		tec = ERR_OK;
		
	fseek(f, 0, SEEK_SET);

	return tec;
}

int get_student_by_pos(FILE *f, size_t index, struct product_t *product)
{
	fseek(f, index * sizeof(struct product_t), SEEK_SET);
	return read_student_from_file(f, product);
}

int put_student_by_pos(FILE *f, size_t index, struct product_t *product)
{
	fseek(f, index * sizeof(struct product_t), SEEK_SET);
	return write_student_into_file(f, product);
}

double average_local(struct product_t product)
{
	return (double)(product.marks[0] + product.marks[1] + product.marks[2] + product.marks[3]) / 4;
}

int product_arr_read(FILE *f, struct product_t *pproducts, size_t *n)
{
	struct product_t product;
	size_t i = 0;
	int rc = ERR_OK;
	while (rc == ERR_OK)
	{
		rc = product_read(f, &product);
		if (rc == ERR_OK)
		{
			if (i < PRODUCT_COUNT)
			{
				pproducts[i] = product;
				i++;
			}
			else
				rc = ERR_PROCESS;
		}
	}
	*n = i;
	
	if (feof(f))
		rc = ERR_OK;
	if (i == 0)
		rc = ERR_EXIST;

	return rc;
}

void product_print(const struct product_t *pproducts, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%s%s", pproducts[i].surname, pproducts[i].name);
		for (size_t j = 0; j < 4; j++)
			printf("%u\n", pproducts[i].marks[j]);
	}
}

/* void product_sort(FILE *newf, struct product_t *pproducts, size_t n)
{
	struct product_t temp;
	for (size_t i = n - 1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (pproducts[j].price < pproducts[j + 1].price)
			{
				temp = pproducts[j];
				pproducts[j] = pproducts[j + 1];
				pproducts[j + 1] = temp;
			}
		}
		
	}
	for (size_t i = 0; i < n; i++)
		fprintf(newf, "%s%s%u\n%u\n", pproducts[i].title, pproducts[i].developer, pproducts[i].price, pproducts[i].count);
}
*/
/* int add_product(FILE *f, struct product_t *pproducts, size_t n)
{
	struct product_t product;
	char buf_title[TITLE_LEN + 2];
	char buf_developer[DEVELOPER_LEN + 2];
	size_t len_title, len_developer;
	size_t pos = 0;
	printf("Enter the name of product: ");
	if (!scanf("%s", buf_title))
		return ERR_PROCESS;
	len_title = strlen(buf_title);
	buf_title[len_title] = '\n';
	buf_title[len_title + 1] = '\0';
	strcpy(product.title, buf_title);
	printf("Enter product developer: ");
	if (!scanf("%s", buf_developer))
		return ERR_PROCESS;
	len_developer = strlen(buf_developer);
	buf_developer[len_developer] = '\n';
	buf_developer[len_developer + 1] = '\0';
	strcpy(product.developer, buf_developer);
	printf("Enter price of product: ");
	if (!scanf("%u", &product.price))
		return ERR_PROCESS;
	
	printf("Enter count of product: ");
	if (!scanf("%u", &product.count))
		return ERR_PROCESS;
	for (size_t i = n - 1; i > 0; i--)
		if (product.price < pproducts[i].price)
		{
			pos = i + 1;
			break;
		}

	for (size_t i = n; i > pos; i--)
		pproducts[i] = pproducts[i - 1];	
	pproducts[pos] = product;
	product_arr_check(pproducts, n + 1);
	for (size_t i = 0; i < n + 1; i++)
		fprintf(f, "%s%s%u\n%u\n", pproducts[i].title, pproducts[i].developer, pproducts[i].price, pproducts[i].count);
	return ERR_OK;
}
*/
int print_end(FILE *f, struct product_t *pproducts, size_t n, char *sub)
{
	size_t len_sub;
	size_t flag;
	size_t count = 0;
	char buf_title[TITLE_LEN + 1];
	len_sub = strlen(sub);
	for (size_t i = 0; i < n; i++)
		if (strstr(pproducts[i].surname, sub) != NULL)
		{
			flag = 1;
			strcpy(buf_title, pproducts[i].surname);
	
			for (size_t j = 0; j < len_sub; j++)	
			{
				if (sub[j] != buf_title[j])
					flag = 0;
			}
			if (flag)
			{
				count++;
				fprintf(f, "%s%s", pproducts[i].surname, pproducts[i].name);
				fprintf(f, "%u %u %u %u\n", pproducts[i].marks[0], pproducts[i].marks[1], pproducts[i].marks[2], pproducts[i].marks[3]);
			}
		}
	if (count == 0)
		return ERR_EXIST;
	return ERR_OK;
}

int delete_stud(FILE *f, struct product_t *pproducts, size_t n)
{
	uint32_t srd = 0;
	uint32_t srd_stud;
	uint32_t srd_studs[n];
	size_t pos[n];
	size_t k = 0;
	size_t len;

	for (size_t i = 0; i < n; i++)
	{
		srd_stud = 0;
		for (size_t j = 0; j < 4; j++)
			srd_stud += pproducts[i].marks[j];
		srd += srd_stud / 4;
		srd_studs[i] = srd_stud;
	}
	srd /= n;
	for (size_t i = 0; i < n; i++)
		if (srd_studs[i] < srd)
		{
			pos[k] = i;
			k++;
		}
	for (size_t i = 0; i < k; i++)
		for (size_t j = pos[i]; j < n; j++)
			pproducts[j] = pproducts[j + 1];
	
	len = n - k;
	
	if (fwrite(pproducts, len * sizeof(struct product_t), 1, f) != 1)
		return ERR_PROCESS;

	return ERR_OK;
}
