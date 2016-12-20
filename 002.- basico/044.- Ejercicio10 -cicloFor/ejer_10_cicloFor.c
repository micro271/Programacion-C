//Factorial de un numero



#include<stdio.h>

int main()
{
	int i,num,mult = 1;
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&num);
	if(num < 0) printf("Un factorial no puede ser negativo\n");
	while(num < 0)
	{
		printf("Digite un numero entero: ");
		fflush(stdin);
		scanf("%i",&num);
	}
	for(i = 1; i <= num; i++)
	{
		mult*=i;
	}
	printf("El factorial del numero %i es: %i",num,mult);
	return 0;
}
