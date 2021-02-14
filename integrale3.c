#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fct(double x)
{
    return sin(x);
}

double integrale(double a, double b, double h, double (f)(double))
{
	double N=(b-a)/h;
	double acc=(f(a)+f(b))/2;
	for (int i=0;i<N;i++)
	{
		acc=acc+f(a+i*h)*h;
	}
	return acc;
	
}

int main()
{
	double a=0,b=2,h=0.1;
	do {
		printf("%.10lf %.10lf\n",h,integrale(a,b,h,fct));
		h = h / 10 ;
	} while( h > 0.00000001 );
    return 0;
}
