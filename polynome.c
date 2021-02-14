#include <stdio.h>
#include <math.h>

double calcul(int degre, double poly[100],int x)
{
    double res,val=0;
    for(int i=0;i<degre;i++){
        //printf("X%d = %.2lf\n", poly[i],i);
        res=poly[i]*pow(x,i);
        val=val+res;
    }
    return val;
} 

double derive(int degre, double poly[100],int x)
{
    double res,val=0;
    for(int i=0;i<degre;i++){
        //printf("X%d = %.2lf\n", poly[i],i);
        res=poly[i]*i*pow(x,i-1);
        val=val+res;
    }
    return val;
}

double afficher(int degre, double poly[100],int x)
{
    for(int i=0;i<degre;i++){
        printf("+(%.2lf)*X^%d", poly[i],i);
    }
    printf("\n");
}

double newton(double polynome, double der, int iter, double err, int x){
    int convergence=0;
    double y;
    int i=1;
    do
    {
        y=polynome/der;
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
    int deg,ncase;
    double tab[100],x;

    printf("Degré polynôme : ");
    scanf("%d", &deg);

    printf("Entrez les %d éléments : ", deg);
    for (ncase = 0; ncase<deg; ncase++)
      scanf("%lf", &tab[ncase]);

    printf("Valeur de x : ");
    scanf("%lf", &x);

    printf("%lf\n",calcul(deg,tab,x));
    printf("%lf\n",derive(deg,tab,x));
    afficher(deg,tab,x);

    printf("Newton=\t%lf\n",newton(calcul(deg,tab,x),derive(deg,tab,x),10,0.1,x));

    return 0;
}
