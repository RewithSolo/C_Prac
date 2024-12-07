#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <strings.h>
#include "funcs.h"

int input_string(char *s)
{
	char *p;
	if (!fgets(s, S + 1, stdin))
			return ERR_IO;
	
	p = strchr(s, '\n');
	if (!p)
		return ERR_IO;

	while (isspace(*p))
		--p;

	*(p + 1) = '\0';

	for (size_t i = 0; i < strlen(s); i++)
		if (isspace(s[i]))
			s[i] = ' ';

	return OK;
}

/*size_t split_array(char *s, char words[][W + 1], size_t *arr_len, char *sep)
{
	size_t j = 0;
	size_t z = 0;

	for (size_t i = 0; s[i] != '\0'; i++)
	{
		if (strchr(sep, s[i]) == NULL)
		{
			words[j][z++] = s[i];
			if (z > W)
				return ERR_PROCESS;
		}
		else
		{
			if (z == 0)
				continue;
			words[j++][z] = '\0';
			z = 0;
		}
	}
	if (z != 0)
		words[j++][z] = '\0';

	*arr_len = j;

	return OK;
}*/

/*int check(char arr[][W + 1], size_t arr_len, char *months[])
{
	if (arr_len != 3)
		return ERR_IO;
	size_t flag = 0;
	size_t m;
	size_t len = strlen(arr[0]);
	for (size_t i = 0; i < M; i++)
		if (strcasecmp(months[i], arr[1]) == 0)
		{
			m = i;
			flag = 1;
			break;
		}
	if (flag == 0)
		return ERR_IO;
	for (size_t i = 0; i < len; i++)
		if (arr[0][i] == '+' || arr[0][i] == '-')
			return ERR_IO;
	
	len = strlen(arr[2]);
	for (size_t i = 0; i < len; i++)
		if (arr[2][i] == '+' || arr[2][i] == '-')
			return ERR_IO;

	if (atoi(arr[0]) > 31 || atoi(arr[0]) < 1 || atoi(arr[2]) < 1)
		return ERR_IO;
	
	if (strcasecmp(arr[1], months[1]) == 0 && ((atoi(arr[0]) > 29 && atoi(arr[2]) % 4 == 0) || (atoi(arr[0]) > 28 && atoi(arr[2]) % 4 != 0) || (atoi(arr[0]) > 28 && atoi(arr[2]) % 100 == 0 && atoi(arr[2]) % 400 != 0)))
		return ERR_IO;
	
	if (strcasecmp(arr[1], months[1]) != 0)
	{
		if (m <= 6 && ((m + 1) % 2 == 0 && atoi(arr[0]) > 30))
			return ERR_IO;
		else if (m > 6 && ((m - 6) % 2 == 0 && atoi(arr[0]) > 30))
			return ERR_IO;
	}
	return OK;
}*/

bool check(const char *s, char *months[])
{
	size_t i = 0;
	char data[W + 1];
	char month[W + 1];
	char year[W + 1];
	size_t c = 0;
	size_t flag = 0;
	size_t m;
	while (isspace(s[i]))
		i++;
	
/*	if (str[i] == '+' || str[i] == '-')
		return false; */
	
	if (!(s[i] >= '0' && s[i] <= '9'))
		return false;

	while (s[i] >= '0' && s[i] <= '9')
	{
		data[c] = s[i];
		c++;
		i++;
	}

	data[c] = '\0';
	c = 0;

	if (!(s[i] == ' '))
		return false;
	
	while (isspace(s[i]))
		i++;
	
	if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
		return false;
	
	while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
	{
		month[c] = s[i];
		c++;
		i++;
	}
	
	month[c] = '\0';
	c = 0;

	if (!(s[i] == ' '))
		return false;

	while (isspace(s[i]))
		i++;
	
	if (!(s[i] >= '0' && s[i] <= '9'))
		return false;
	
	while (s[i] >= '0' && s[i] <= '9')
	{
		year[c] = s[i];
		c++;
		i++;
	}

	year[c] = '\0';
	c = 0;
	if (s[i])
		return false;	

	for (size_t i = 0; i < M; i++)
		if (strcasecmp(months[i], month) == 0 && !flag)
		{
			m = i;
			flag = 1;
		}
	
	if (flag == 0)
		return false;

	if (atoi(data) > 31 || atoi(data) < 1 || atoi(year) < 1)
		return false;
	
	if (strcasecmp(month, months[1]) == 0 && ((atoi(data) > 29 && atoi(year) % 4 == 0) || (atoi(data) > 28 && atoi(year) % 4 != 0) || (atoi(data) > 28 && atoi(year) % 100 == 0 && atoi(year) % 400 != 0)))
		return false;
	
	if (strcasecmp(month, months[1]) != 0)
	{
		if (m <= 6 && ((m + 1) % 2 == 0 && atoi(data) > 30))
			return false;
		else if (m > 6 && ((m - 6) % 2 == 0 && atoi(data) > 30))
			return false;
	}
	
	return true;
}
