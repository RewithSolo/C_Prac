#include <stdio.h>

int main()
{
	double r1, r2, r3, robj;
	scanf("%lf %lf %lf", &r1, &r2, &r3);
	
	robj = 1 / (1 / r1 + 1 / r2 + 1 / r3);
	
	printf("%.6lf", robj);
}
