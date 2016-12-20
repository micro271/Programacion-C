/*
	Hacer un arreglo de estructura llamad atleta para N atletas que tengan los siguientes miembros:
	nombre,pais,numero_medalla. y debuelva el dato(nombre,pais)del atleta que ha ganado el mayor numero de medallas
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char nombre[30];
	char pais[20];
	unsigned int numero_medallas;
}atleta;
void pedir(atleta * a);
void imprimir(atleta * a);
int main(void)
{
	unsigned int largo;
	printf("Cuantas personas deceas registrar: ");
	fflush(stdin);
	scanf("%u",&largo);
	
	atleta a[largo];
	int i,n;
	for(i = 0; i < largo; i++)
	{
		pedir(&a[i]);
	}
	
	int numero_medallas[largo];
	for(i = 0; i < largo; i++)
	{
		numero_medallas[i] = (*a).numero_medallas;
	}
	int aux;
	for(i = 0; i < largo-1; i++)
	{
		for(n = 0; n < largo; n++)
		{
			if(numero_medallas[n] < numero_medallas[n+1])
			{
				aux = numero_medallas[n];
				numero_medallas[n] = numero_medallas[n+1];
				numero_medallas[n+1] = aux;
			}
		}
	}
	
	for(i = 0; i < largo; i++)
	{
		if(a[i].numero_medallas > numero_medallas[0])
		{
			imprimir(&a[i]);
		}	
	}
	system("pause");
	return 0;
}

void pedir(atleta * a)
{
	int i;
	printf("Nombre: ");
	fflush(stdin);
	gets((*a).nombre);	
	for(i = 0; i < strlen((*a).nombre); i++)
	{
		if(i == 0)
		{
			(*a).nombre[0] = toupper((*a).nombre[0]);
		}
		if((*a).nombre[i] == ' ')
		{
			(*a).nombre[i+1] = toupper((*a).nombre[i+1]);
		}
	}
	
	printf("Pais: ");
	fflush(stdin);
	gets((*a).pais);
	for(i = 0; i < strlen((*a).pais); i++)
	{
		if(i == 0)
		{
			(*a).pais[0] = toupper((*a).pais[0]);
		}
		if((*a).pais[i] == ' ')
		{
			(*a).pais[i+1] = toupper((*a).pais[i+1]);
		}
	}
	
	printf("Medallas: ");
	fflush(stdin);
	scanf("%u",&(*a).numero_medallas);
}

void imprimir(atleta * a)
{
	printf("\n\tEl atleta con mas medallas es: %s\n",(*a).nombre);
	printf("Nombre: %s\n",(*a).nombre);
	printf("Pais: %s\n",(*a).pais);
	printf("Medallas ganadas: %u\n",(*a).numero_medallas);
}











