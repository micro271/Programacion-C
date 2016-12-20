/*
	Hacer una lista de 10 numeros. luego hacer que el usuario digite un numero, y a travez
	de una busqueda secuencial determinar si el numero existe en la lista o no y ademas indicar 
	en que posicion se encuentra
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
	int x,num[10],i,el,m;
	srand(time(NULL));
	for(i = 0; i < 10; i++)
	{
		x = 1 + rand() % ((10 + 1) - 1);
		num[i] = x;
	}
	char * existe = "No";
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&el);
	
	for(i = 0; i < 5; i++)
	{
		if(num[i] == el)
		{
			m = i;
			if(strcmp(existe,"No") == 0)
			{
				existe = "Si";
			}
		}
	}
	printf("El numero existe?\t->\t%s\n",existe);
	if(strcmp(existe,"Si") == 0)
	{
			printf("El elemento %i se encuentra en la posicion %i\n",el,m);
	}
	
	
	system("pause");
	return 0;
}
