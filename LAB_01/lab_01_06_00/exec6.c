#include <stdio.h>
#include <math.h>
#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define EPS 0.000001

// Функция для вычисления расстояния между двумя точками
double dist(double xa, double xb, double ya, double yb)
{
	return sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
}

// Функция для определения типа треугольника
int type_check(double ab, double bc, double ac)
{	
	int type;
	if (fabs(ab * ab + bc * bc - ac * ac) < EPS || fabs(bc * bc + ac * ac - ab * ab) < EPS || fabs(ac * ac + ab * ab - bc * bc) < EPS)
	{
		type = 1;
	}
	else if (ab * ab + bc * bc > ac * ac && bc * bc + ac * ac > ab * ab && ac * ac + ab * ab > bc * bc) 
	{
		type = 0;
	}
	else
	{
		type = 2;
	}
	return type;
}

// Главная функция
int main()
{
	double xa, ya, xb, yb, xc, yc, ab, bc, ac;
	int type;
	
	printf("Input coordinates A, B, C: ");
	if (scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc) != 6)
	{
		printf("You don't entered six coordinates!");
		return ERR_IO;
	}

	ab = dist(xa, xb, ya, yb);
	bc = dist(xc, xb, yc, yb);
	ac = dist(xa, xc, ya, yc);

	if (ab + bc <= ac || bc + ac <= ab || ab + ac <= bc)
	{
		printf("Triangle is not exist!");
		return ERR_RANGE;
	}

	type = type_check(ab, bc, ac);
	printf("The triangle type: %d\n", type);
	return OK;
}
