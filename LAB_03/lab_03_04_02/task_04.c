#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "funcs.h"

int main()
{
	int arr[N][M];
	size_t a_n;
	int max_el;
	int rc = input(arr, &a_n);
	if (rc == ERR_IO)
	{
		printf("Error Input");
		return ERR_IO;
	}
	else if (rc == ERR_RANGE)
	{
		printf("Error Range");
		return ERR_RANGE;
	}
	if (!check_inp(arr, a_n, &max_el))
	{
		printf("Error exist num '5' char");
		return ERR_EXIST;
	}
	max_elem(arr, a_n, &max_el);
	printf("%d\n", max_el);
	return OK;
}
