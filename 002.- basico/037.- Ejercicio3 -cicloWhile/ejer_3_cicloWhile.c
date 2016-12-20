//Multiplos de 3 hasta el numero n {n e N}

#include <stdio.h>

int main()
{
	int num,y = 0;
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%i",&num);
	while(y <= num)
	{
		(y%3==0) ? printf("\t%i -> multiplo de 3\n",y) : printf("\t%i -> no es multiplo de 3\n",y);
		y++;
	}
}
