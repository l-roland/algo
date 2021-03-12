// gcc complexe3.c -o complexe3 -lm
// ./complexe3

#include <stdio.h>
#include <math.h>

//Création d'une structure polynome_t
struct polynome_t
{
	// Pour traiter le degré
    double deg;
    
    // Pour traiter les valeurs du polynome
    double val[100];
};

//Définir cplx au lieu de struct polynome_t
typedef struct polynome_t poly;

//Affiche sous forme de texte le polynôme en fonction du degré
double afficher(int deg, double poly[100])
{
	//Pour i de 0 à degré inclus avec i=i+1
    for(int i=0;i<=deg;i++)
    {
		//Affihe le contenu de la case i
        printf("+%lf*X^%d",poly[i],i);
    }
    
    //Retour à la ligne quand tout est affiché
    printf("\n");
}

//Calcul du delta quand le polynôme est de degré 2
double delta(double poly[100])
{
	//b²-4ac
    double res=pow(poly[1],2)-4*poly[0]*poly[2];
    
    //Retourne le résultat du delta
    return res;
}

//Calcul des racines en fonction de delta
double racine(double poly[100], double deltaa)
{
	//Si delta>0
	if (deltaa>0)
	{
		//x1=(-b-racine(delta))/(2a)
		//x2=(-b+racine(delta))/(2a)
		double x1,x2;
		x1=(-poly[1]-sqrt(deltaa))/(2*poly[0]);
		x2=(-poly[1]+sqrt(deltaa))/(2*poly[0]);
		printf("%f\n",x1);
		printf("%f\n",x2);
	}
	
	//Si delta=0
	if (deltaa==0)
	{
		//x=-b/2a
		double x;
		x=(-poly[1])/(2*poly[0]);
		printf("%f\n",x);
	}
	
	if (deltaa<0)
	{
		//Aucune racine
		printf("Pas de racine\n");
	}
}

//double division(poly[100])
//{
//}

//Fonction principale
int main()
{
	//Initialise la variable toto en mode complexe
    poly toto;
    
    //Saisie utilisateur du degré
    printf("Degré du polynome : ");
    scanf("%le",&toto.deg);

	//Saisie utilisateur des éléments
    printf("Indiquez les %f éléments : ",toto.deg+1);
    
    //On insère dans n cases
    for(int n=0;n<=toto.deg;n++)
    {
        scanf("%lf",&toto.val[n]);
    }

	//On appelle la fonction qui affiche les polynomes
    afficher(toto.deg,toto.val);

	//Si de degré 2
    if(toto.deg==2)
    {
		//Appel de la fonction delta et de la fonction racine
		double del=delta(toto.val);
        printf("%lf\n",del);
        racine(toto.val,toto.deg);
    }
    
    //Retour du code d'erreur 0
    return 0;    
}

