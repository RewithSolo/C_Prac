#include <stdio.h>
#include <math.h>

int main()
{
	double xa, ya, xb, yb, xc, yc, ab, bc, ac, p;
	scanf("%lf %lf", &xa, &ya);
	scanf("%lf %lf", &xb, &yb);
	scanf("%lf %lf", &xc, &yc);

	ab = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
	bc = sqrt((xb - xc) * (xb - xc) + (yc - yb) * (yc - yb));
	ac = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
	p = ab + bc + ac;
	
	printf("Perimetr is %.6lf", p);
	return 0;
}
