// gcc complexe2.c -o complexe2 -lm
// ./complexe2

#include <stdio.h>
#include <math.h>

//Création d'une structure complex_t
struct complex_t
{
    // Pour traiter la partie réelle
    double re;

    // Pour traiter la partie imaginaire
    double im;
};

//Définir cplx au lieu de struct complex_t
typedef struct complex_t cplx;

//Détermine le réel d'un complexe
double complex_real(cplx x)
{
    return x.re;
}

//Détermine l'imaginaire d'un complexe
double complex_im(cplx x)
{
    return x.im;
}

//Détermine la somme de 2 complexes
cplx complex_add(cplx x, cplx y)
{
    cplx res;
    res.re=x.re+y.re;
    res.im=x.im+y.im;
    return res;
}

//Détermine le res de sub de 2 complexes
cplx complex_sub(cplx x, cplx y)
{
    cplx res;
    res.re=x.re-y.re;
    res.im=x.im-y.im;
    return res;
}

//Détermine le produit de 2 complexes
cplx complex_mul(cplx x, cplx y)
{
    cplx res;
    res.re=((x.re*y.re)-(x.im*y.im));
    res.im=((x.re*y.im)+(x.im*y.re));
    return res;
}

//Détermine le résultat de la division de 2 complexes
int complex_div(cplx* res, cplx x, cplx y)
{
    if((y.re==0) && (y.im==0))
    {
		return -1;
	}
	res -> re=(x.re*y.re+x.im*y.im)/(pow(y.re,2)+pow(y.im,2));
	res -> im=(x.im*y.re-x.re*y.im)/(pow(y.re,2)+pow(y.im,2));
    return 0;
}

//Détermine le module d'un complexe
double complex_mod(cplx x)
{
    return (sqrt(pow(x.re,2)+pow(x.im,2)));
}

//Détermine le conjugué d'un complexe
cplx complex_conj(cplx x)
{
    return x;
}

int main()
{
	
    //Complexe toto avec re=5 et im=3
    cplx toto={5,6};

    //Complexe tata avec re=8 et im=5
    cplx tata={5,0};

    //Pour afficher 5+j3
    printf("%lf+j%lf\n",toto.re,toto.im);

    //Appel de la fonction qui détermine un réel
    printf("%lf\n",complex_real(toto));

    //Appel de la fonction qui détermine un imaginaire
    printf("%lf\n",complex_im(toto));

    //Appel de la fonction qui détermine la somme de 2 complexes
    cplx add=complex_add(toto,tata);
    printf("%lf+j%lf\n",add.re,add.im);

    //Appel de la fonction qui détermine le rés sub de 2 complexes
    cplx sub=complex_sub(toto,tata);
    printf("%lf+j%lf\n",sub.re,sub.im);

    //Appel de la fonction qui détermine le produit de 2 complexes
    cplx mul=complex_mul(toto,tata);
    printf("%lf+j%lf\n",mul.re,mul.im);

    //Appel de la fonction qui détermine le résultat de div de 2 complexes
    cplx div;
    int erreur;
    erreur=complex_div(&div,toto,tata);
    
    if (erreur==0)
    {
		printf("%lf+j%lf\n",div.re,div.im);
	}
	else
	{
		printf("Div par 0\n");
	}  

    //Appel de la fonction qui détermine le module de toto
    printf("%lf\n",complex_mod(toto));

    //Appel de la fonction qui détermine le conjugué de toto
    cplx conj=complex_conj(toto);
    printf("%lf+j%lf\n",conj.re,conj.im);

    //Retourne le code d'erreur 0
    return 0;
}
