//Multiplos de 5 desdde 1 hasta n

#include<stdio.h>

int main()
{
	int num,x;
	
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%i",&num);
	if(num < 0) printf("Solo numeros mayores a 1\n");
	while(num < 1)
	{
		printf("Ingrese un numero nuevamente: ");
		fflush(stdin);
		scanf("%i",&num);
	}
	x = 1;
	while(x <= num)
	{
		if(x%5==0) printf("\t%i es multiplo de 5\n",x);
		x++;
	}
	
	return 0;
}
