#include <stdio.h>
#include <math.h>

double fonction(double x)
{
return cos(x);
}


double Splus(double (*f)(double),double pole1, double pole2, double h) 
{
        double x=pole1;
        double aire;
        double airetot=0;
        double l;
        while (x<pole2) 
        {
            if (f(x)>f(x+h)){
                l=f(x);
            }
            else{
                l=f(x+h);
            }
                x=x+h;
                aire=h*l;
                airetot=aire+airetot;
        }
        return airetot;
}

double Smoins(double (*f)(double),double pole1, double pole2, double h) 
{
        double x=pole1;
        double aire;
        double airetot=0;
        double l;
        while (x<pole2) 
        {
            if (f(x)>f(x+h)){
                l=f(x+h);
            }
            else{
                l=f(x);
            }
                x=x+h;
                aire=h*l;
                airetot=aire+airetot;
        }
        return airetot;
}

int main()
{
double Iplus;
double Imoins;
double h;
h=0.001;
int i;
    for (i=0; i<4; i++)
    {   printf ("h:%lf\n",h);
        Iplus=Splus(fonction,1,2,0.001);
	Imoins=Smoins(fonction,1,2,0.001);
	printf("integrale + : %lf \n",Iplus);
	printf("integrale - : %lf \n",Imoins);
        h=h/10;
    }
}



------------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>

double fonction(double x)
{
return cos(x)*cos(x);
}


double Splus(double (*f)(double),double pole1, double pole2, double h) 
{
        double x=pole1;
        double aire;
        double airetot=0;
        double l;
        while (x<pole2) 
        {
            if (f(x)>f(x+h)){
                l=f(x);
            }
            else{
                l=f(x+h);
            }
                x=x+h;
                aire=h*l;
                airetot=aire+airetot;
        }
        return airetot;
}

double Smoins(double (*f)(double),double pole1, double pole2, double h) 
{
        double x=pole1;
        double aire;
        double airetot=0;
        double l;
        while (x<pole2) 
        {
            if (f(x)>f(x+h)){
                l=f(x+h);
            }
            else{
                l=f(x);
            }
                x=x+h;
                aire=h*l;
                airetot=aire+airetot;
        }
        return airetot;
}
int main()
{
double Iplus;
double Imoins;
double h;
h=0.001;
int i;
    for (i=0; i<4; i++)
    {   printf ("h:%lf\n",h);
        Iplus=Splus(fonction,1,2,0.001);
	Imoins=Smoins(fonction,1,2,0.001);
	printf("integrale + : %lf \n",Iplus);
	printf("integrale - : %lf \n",Imoins);
        h=h/10;
    }
}
