/*
	Libreria math.h
	
	ceil(x)		->	Redondea al proximo entero mas cercano;
	fobs(x)		->	Devuelve el valor absoluto de x;
	floor(x)	->	Redondea por defecte al entero mas proximo;
	fmod(x,y)	->	Calcula el resto de la divicion x/y;
	pow(x,y) 	->	Calcula x elevada a la potencia de y;
	sqrt(x)		->	Devuelve la raiz cuadrada de x;
*/

#include<stdio.h>

void funcion_matematica();
int main()
{
	funcion_matematica();
	return 0;
}

void funcion_matematica()
{
	float x,cambio;
	
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%f",&x);
	 
	cambio = ceil(x);
	printf("ceil(%.2f)\t->\t%.2f\n",x,cambio);
	
	cambio = fabs(x);
	printf("fabs(%.2f)\t->\t%.2f\n",x,cambio);
	
	cambio = floor(x);
	printf("floor(%.2f)\t->\t%.2f\n",x,cambio);
	
	cambio = sqrt(x);
	printf("sqrt(%.2f)\t->\t%.2f",x,cambio);
	
	int a,b,cambio2;
	do
	{
		printf("Digite dos numeros separados por espacios: ");
		fflush(stdin);
		scanf("%i %i",&a,&b);
	}while(a < b);
	
	cambio2 = fmod(a,b);
	printf("fmor(%i,%i)\t->\t%i\n",a,b,cambio2);
	
	cambio2 = pow(a,b);
	printf("pow(%i,%i)\t->\t%i",a,b,cambio2);
}
