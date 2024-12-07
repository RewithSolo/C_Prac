#include <stdio.h>
#include <math.h>
#define ERR_IO 1
#define ERR_RANGE 2
#define OK 0

// Функция для возведения числа в степень
int degree(int a, int n)
{
	int res;
	res = 1;
	for (int i = 1; i <= n; i++)
	{
		res *= a;
	}
	return res;
}

// Главная функция
int main()
{
	int a, n, res;
	printf("Enter a and n: ");
	if (scanf("%d %d", &a, &n) != 2)
	{
		printf("You dont enter two numbers!");
		return ERR_IO;
	}
	else if (n <= 0)
	{
		printf("You enter non positive n!");
		return ERR_RANGE;
	}
	
	res = degree(a, n);
	printf("Result - %d\n", res);
	return OK;
}
