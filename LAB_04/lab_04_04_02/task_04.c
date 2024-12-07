#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>
#include "funcs.h"

int main(void)
{
//    char sep[] = " ";
	char *months[] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	char s[S + 1];
	int rc = input_string(s);
	if (rc != OK)
		return rc;
	
/*  size_t arr_len;
	char arr[S / 2 + 1][W + 1];
	rc = split_array(s, arr, &arr_len, sep);*/
	bool tc = check(s, months);
//    rc = check(arr, arr_len, months);
	if (tc != true)
		printf("NO");
	else
		printf("YES");

	return OK;
}

