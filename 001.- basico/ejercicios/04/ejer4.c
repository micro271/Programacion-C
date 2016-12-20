#include <stdio.h>

int main(void)
{
	int i;
	int tamanio;
	printf("Ingresa la cantidad de elementos que deceas ejecutar: ");
	fflush(stdin);
	scanf("%i",&tamanio);
	fflush(stdin);
	
	i = 0;
	while(tamanio >= i)
	{
		if(tamanio%2 == 0) printf("%i es par\n",tamanio);
		tamanio--;
	}
	return 0;
}
