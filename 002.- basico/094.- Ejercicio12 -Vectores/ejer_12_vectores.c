/*Hacer un programa que pida al usuario el numero de elemento de un array, y rellenar el array con numeros 
aleatorios, luego pedir al usuario un numero y hacer una busqueda secuencial para ver si el numero
existe o no, tambien regresar la posicion*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	unsigned int largo;
	do
	{	
		printf("Digite la cantidad de elementos: ");
		fflush(stdin);
		scanf("%i",&largo);
	}while(largo < 0);
	
	int elemento[largo];
	int i,x;
	for(i = 0; i < largo; i++)
	{
		x = 1 + rand() % ((largo + 1) - 1);
		elemento[i] = x;
	}

	int numero, contador = 0,m;
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&numero);
	char preg[2];
	for(i = 0; i < largo; i++)
	{
		if(elemento[i] == numero)
		{
			contador++;
			if(strcmp(preg,"So") != 0)
			{
				strcpy(preg,"Si");
			}
		}
		else
		{
			if(i == largo -1)
			{
				if(strcmp(preg,"Si") != 0)
				{
					strcpy(preg,"No");
				}
			}
		}
	}
	
	printf("El elemento %i existe?\t-> %s\n",numero,preg);
	if(strcmp(preg,"Si") == 0)
	{
		printf("La cantidad de %i que hay en el array es\t-> %i\n",numero,contador);
	}
	system("pause");
	return 0;
}
