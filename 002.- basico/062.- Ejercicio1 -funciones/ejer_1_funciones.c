//Determinar si un numero es par o impat


#include<stdio.h>

int parOImparInt(int num);
void parOImparVoid(int numero);
int main()
{
	int x;
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%i",&x);
	if(parOImparInt(x) == 0)
	{
		printf("El numero %i es Par\n",x);
	}
	else printf("El numero %i es Impar\n",x);
	
	parOImparVoid(x);

	return 0;
}

int parOImparInt(int num)
{
	if(num%2 == 0) return 0;
	else return 1;
}

void parOImparVoid(int numero){
	if(numero%2==0) printf("El numero %i es par",numero);
	else printf("El numero %i es impar",numero);
}


