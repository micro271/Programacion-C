/*
	**Funciones trigonometricas
	
		acos(x) 		->	Calcula el arc-cos de x;
		asin(x)			->	Calcula el arc-sen de x;
		atan(x)			->	Calcula el arc-tg de x;
		cos(x) 			->	Calcula el coseno del angulo x, en radianes;
		sin(x)			->	Calcula el seno del angulo x, en radianes;
		tan(x)			->	Calcula la tangente del angulo x, en radianes;
*/

#include<stdio.h>
#include<math.h>
void funcion_trigonometrica();
int main()
{
	funcion_trigonometrica();
	
	return 0;
}

void funcion_trigonometrica()
{
	float ac,as,at,c,s,t, cambio = 0;
	
	//Arco coseno
	printf("\tArco coseno\n");
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%f",&ac);
	while(ac >= 1 || ac <= -1)
	{
		printf("Arco coseno es entre -1 y 1: ");
		fflush(stdin);
		scanf("%f",&ac);
		
	}
	cambio = acos(ac);
	printf("acos(%.2f)\t->\t%.2f\n",ac,cambio);
	
	//Arco seno
	printf("\tArco seno\n");
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%f",&as);
	while(ac >= 1 || ac <= -1)
	{
		printf("Arco seno es entre -1 y 1: ");
		fflush(stdin);
		scanf("%f",&as);
		
	}
	cambio = asin(as);
	printf("asin(%.2f)\t->\t%.2f\n",as,cambio);
	
	
	//Arco tangente
	printf("\tArco tangente\n");
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%f",&at);
	
	cambio = atan(at);
	printf("atan(%.2f)\t->\t%.2f",at,cambio);
	
	//coseno
	
	printf("\n\tCoseno\n");
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%f",&c);
	
	cambio = cos(c);
	printf("cos(%.2f)\t->\t%.2f",c,cambio);
	
	//seno
	printf("\n\tSeno\n");
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%f",&s);
	
	cambio = sin(s);
	printf("sin(%.2f)\t->\t%.2f",s,cambio);
	
	
	//Tanfente
	printf("\n\tTangente\n");
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%f",&t);
	
	cambio = tan(t);
	printf("tan(%.2f)\t->\t%.2f",t,cambio);
}
