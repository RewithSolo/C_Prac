#include <stdio.h>
#include <stdbool.h>
#include "funcs.h"

int main()
{
	int arr[N][M];
	int a[M];
	size_t a_n, a_m;
	int rc = input(arr, &a_n, &a_m);
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
	create_arr(arr, a, a_m, a_n);
	print_arr(a, a_m);
	return OK;
}
