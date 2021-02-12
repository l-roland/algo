#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    float res=(1/sqrt(x))-12*cos(x);
    return res;
}

float df(float x)
{
    float res=(12*sin(x)-1/(2*pow(x,3/2)));
    return res;
}

float tan1(float(fct)(float), float(der)(float), float x)
{
    float a=der(x);
    return a;
}

float tan2(float(fct)(float), float(der)(float), float x)
{
    float b=fct(x)-der(x)*x;
    return b;
}

float newton(float(fct)(float), float(der)(float), int iter, float err, float x){
    int convergence=0;
    float y;
    int i=1;
    
    do
    {
        y=fct(x)/der(x);
        if (fabs(x)<=err){
            convergence=1;
        }
        else
        {
            x=x-y;
            printf("%d=\t%f\n",i,x);
            i++;
        }
    }while((i<=iter) && (!convergence));

    return x;
}

int main()
{
    float x;
    printf("Valeur de x : ");
    scanf("%f", &x);

    printf("f(x)=\t%f\n",f(x));
    printf("f'(x)=\t%f\n",df(x));
    printf("tanA=\t%f\n",tan1(f,df,x));
    printf("tabB=\t%f\n",tan2(f,df,x));
    printf("Newton=\t%f\n",newton(f,df,10,0.0001,x));
    return 0;
}
