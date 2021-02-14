#include <stdio.h>
#include <math.h>

double polynome(int degre, double poly[100]){
    for(int i=0;i<degre;i++){
        printf("X%d = %.2lf\n", poly[i],i);
    }
} 

int main()
{
    int deg,ncase;
    double tab[100];

    printf("Degré polynôme : ");
    scanf("%d", &deg);

    printf("Entrez les %d éléments : ", deg);
    for (ncase = 0; ncase<deg; ncase++)
      scanf("%lf", &tab[ncase]);

    polynome(deg,tab);

    return 0;
}
