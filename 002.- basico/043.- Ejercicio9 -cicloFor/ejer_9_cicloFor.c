/*Determinar si un numero es primo o no*/


#include<stdio.h>

int main()
{
	int num,i,contador = 0;
	printf("Digite un numero: ");
	scanf("%i",&num);
	
	for(i = 1; i <= num; i++)
	{
		if(num%i == 0) contador++;
	}
	
	if(contador == 2) printf("El numero %i es primo",num);
	else printf("El numero %i no es primo",num);
	
}
