#include <stdio.h>
#include <math.h>
#define OK 0
#define ERR_IO 1

// Function calculate the sum of sequence
int calc_res(double *res)
{
	double cur, sum, count;
	cur = 0;
	count = 1.0;
	sum = 0;
	printf("Enter the numbers. If you want to stop, enter negative num: ");
	if (scanf("%lf", &cur) != 1)
	{
		return ERR_IO;
	}
	if (cur < 0)
	{
		return ERR_IO;
	}
	while (cur >= 0)
	{	
		sum += sqrt(count + cur);
		count++;
		if (scanf("%lf", &cur) != 1)
		{
			return ERR_IO;
		}
	}
	
	*res = (1 / (count - 1)) * sum;
	return OK;
}

// The main function
int main()
{
	double res;
	int code;
	code = calc_res(&res);
	if (code == 0)
	{
		printf("%.6lf\n", res);
	}
	else if (code == 1)
	{
		printf("IO Error");
	}
	return code;
}

