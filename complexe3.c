// gcc complexe3.c -o complexe3 -lm
// ./complexe3

#include <stdio.h>
#include <math.h>

struct polynome_t
{
    double deg;
    double val[100];
};

typedef struct polynome_t poly;

double afficher(int deg, double poly[100])
{
    for(int i=0;i<=deg;i++)
    {
        printf("+%lf*X^%d",poly[i],i);
    }
    printf("\n");
}

double delta(double poly[100])
{
    double d=pow(poly[1],2)-4*poly[0]*poly[2];
    return d;
}

int main()
{
    poly toto;
    printf("Degré du polynome : ");
    scanf("%le",&toto.deg);

    printf("Indiquez les %f éléments : ",toto.deg+1);
    for(int n=0;n<=toto.deg;n++)
    {
        scanf("%lf",&toto.val[n]);
    }

    afficher(toto.deg,toto.val);

    if(toto.deg==2)
    {
        printf("%lf\n",delta(toto.val));
    }
}
