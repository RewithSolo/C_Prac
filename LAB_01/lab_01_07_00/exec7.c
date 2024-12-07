#include <stdio.h>
#include <math.h>
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

// Функция для подсчета бесконечного ряда до точности эпсилон
double calc_res(double x, double eps)
{
	double cur, sum, count;
	sum = 1;
	count = 2;
	cur = x;
	while (fabs(cur) >= eps)
	{
		sum += cur;
		cur = (cur * x) / count;
		count += 1;
	}
	return sum;
}

// Главная функция
int main()
{
	double x, sum, eps, f, delta, sigma;
	
	if (scanf("%lf %lf", &x, &eps) != 2)
	{
		printf("Input Error");
		return ERR_IO;
	}
	else if (eps <= 0 || eps > 1)
	{
		printf("Epsilon not in range from zero to one");
		return ERR_RANGE;
	}
	sum = calc_res(x, eps);
	f = exp(x);
	delta = fabs(f - sum);
	sigma = fabs(f - sum) / fabs(f);
	printf("%.6lf %.6lf %.6lf %.6lf", sum, f, delta, sigma);
	return OK;
}	
