/*Hacer un programa que pida por pantalla un numero del 1 al 10 y mediante un procedimiento
muestre por pantalla el numero escrito en letras*/

#include<stdio.h>
#include<string.h>

int numeros(int num);

int main()
{
	int x;
	do{
		printf("Digite un numero del 1 al 10: ");
		fflush(stdin);
		scanf("%i",&x);
	}while(x < 1 || x > 10);
	
	printf("El numero que digitaste es: %s",numeros(x));
	return 0;
}

int numeros(int num)
{
	char * numero;
	switch(num)
	{
		case 1: 
			numero = "Uno";
			break;
		case 2:
			numero = "Dos";
			break;
		case 3:
			numero = "Tres";
			break;
		case 4:
			numero = "Cuatro";
			break;
		case 5:
			numero = "Cinco";
			break;
		case 6:
			numero = "Seis";
			break;
		case 7:
			numero = "Siete";
			break;
		case 8:
			numero = "Ocho";
			break;
		case 9:
			numero = "Nueve";
			break;
		case 10:
			numero = "Diez";
			break;
	}
	return numero;
}
