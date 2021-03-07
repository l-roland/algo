#include <stdio.h>
#include <math.h>

double fonction(double x)
{
return cos(x);
}


double integrale(double (*f)(double),double pole1, double pole2, double h) 
{
        double x=pole1;
        double aire;
        double airetot=0;
      
        while (x<pole2) 
        {
                x=x+h;
                aire=(((x+h)-x)/6)*(f(x)+4*f((x+(x+h))/2)+f(x+h));
                airetot=aire+airetot;
        }
        return airetot;

}

int main()
{

double I;
double h;
h=0.001;
int i;
    for (i=0; i<4; i++)
    {   printf ("h:%lf\n",h);
        I=integrale(fonction,1,2,h);
        printf("integrale : %lf \n",I);
        h=h/10;
    }
return 0;   
}
