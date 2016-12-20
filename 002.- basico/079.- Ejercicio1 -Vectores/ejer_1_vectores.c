/*Copiar el contenido de un array de 5 elemento en otro array*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int i;
	int n;
	int vector[5];
	
	srand(time(NULL));
	
	for(i = 0; i < 5; i++)
	{
		n = 1 + rand() % ((10 + 1) - 1); //limite_inferior+rand()%(limite_superior-1)+limite_inferior;
		vector[i] = n;
		printf("%i\n",vector[i]);
	}
	int *copiar_vector[5];
	for(i = 0; i < 5; i++)
	{
		copiar_vector[i] = &vector[i];
		printf("%i, ",*copiar_vector[i]);
	}
	getch();
	return 0;
}

