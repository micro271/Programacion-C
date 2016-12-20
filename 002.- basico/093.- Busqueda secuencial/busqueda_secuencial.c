/*
	**Busqueda secuencial
	busca un numero dentro de una lisa, esta lista puede o no estar ordenada
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	int num[100],i,aleatorio;
	for(i = 0; i < 100; i++)
	{
		aleatorio = 1 + rand() % ((100 + 1) - 1);
		num[i] = aleatorio;
	}
	int el,contador = 0;
	do
	{
		printf("Digite un numero del 1 al 100: ");
		fflush(stdin);
		scanf("%i",&el);
	}while(el <  1 && el > 100);
	char existe = 'F';
	for(i = 0; i < 100; i++)
	{
		if(el == num[i])
		{
			contador++;
			if(existe == 'F')
			{
				existe = 'V';
			}
		}
	}
	printf("En el vector unidimencional existe el numero %i?\t\t->\t%c\n",el,existe);
	printf("Cuantos numero '%i' hay en el vector unidimenciona?\t->\t%i\n",el,contador);
	system("pause");
	return 0;
}
