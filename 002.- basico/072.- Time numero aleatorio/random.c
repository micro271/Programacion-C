/*
	**Funcion aleatoria
		srand(time(NULL)); para darle el poder a la pc para generar un numero aleatorio
		
		variable = limite_inferior + rand() % ((limite_superior + 1) - limite_inferio);
*/


#include<stdio.h>
#include<time.h>
void funcion_aleatoria();
int main()
{
	funcion_aleatoria();
	return 0;
}

void funcion_aleatoria()
{
	int i,numero,l_i,l_s;
	
	srand(time(NULL));
	
	printf("Digite el limite inferior: ");
	fflush(stdin);
	scanf("%i",&l_i);
	
	printf("Digite el limite superior: ");
	fflush(stdin);
	scanf("%i",&l_s);
	for(i = 1; i <= 10; i++)
	{
		numero = l_i + rand() % ((l_s+1) - l_i);
		printf("%i.\n",numero);
	}
	
}











