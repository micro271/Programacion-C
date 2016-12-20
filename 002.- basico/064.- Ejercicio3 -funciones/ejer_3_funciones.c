/*Hacer un programa que muestre un menu con las opciones sumar, restar, multiplicar y dividir, el programa
solisitara una opcion y realiza la tarea elegida, se debe usar un procedimiento*/
#include<stdio.h>
#include<string.h>
void menu();
int suma();
int resta();
int mult();
int div();

int main()
{
	menu();
	
	return 0;
}


void menu()
{
	int opc,val;
	printf("\tQue operacion matematica quiere realizar: \n");
	printf("1. Sumar\n");
	printf("2. Restar\n");
	printf("3. Multiplicar\n");
	printf("4. Dividir\n");
	printf("\nIngrese una opcion: ");
	fflush(stdin);
	scanf("%i",&opc);
	while(opc < 0 || opc > 4)
	{
		printf("Opcion invalida. Por favor eliga nuevamente una opcion: ");
		fflush(stdin);
		scanf("%i",&opc);
	}
	
	if(opc == 1)
	{
		val = suma();
		printf("La suma de ambos numeros es %i",val);
	}
	else if(opc == 2)
	{
		val = restar();
		printf("La resta de ambos numeros es %i",val);
	}
	else if(opc == 3)
	{
		val = mult();
		printf("La multiplicacion de ambos numeros es %i",val);
	}
	else if(opc == 4)
	{
		val = div();
		printf("La divicion de ambos numeros es %i",val);
	}
}

int suma()
{
	int x,y;
	printf("Digite el primer numero: ");
	fflush(stdin);
	scanf("%i",&x);
	printf("Digite el segundo numero: ");
	fflush(stdin);
	scanf("%i",&y);
	int suma = 0;
	suma = x + y;
	
	return suma;
}

int restar()
{
	int x,y;
	printf("Digite el primer numero: ");
	fflush(stdin);
	scanf("%i",&x);
	printf("Digite el segundo numero: ");
	fflush(stdin);
	scanf("%i",&y);
	int resta = 0;
	resta = x - y;
	
	return resta;
}

int mult()
{
	int x,y;
	printf("Digite el primer numero: ");
	fflush(stdin);
	scanf("%i",&x);
	printf("Digite el segundo numero: ");
	fflush(stdin);
	scanf("%i",&y);
	int mult = 0;
	mult = x * y;
	
	return mult;
}

int div()
{
	int x,y;
	printf("Digite el primer numero: ");
	fflush(stdin);
	scanf("%i",&x);
	printf("Digite el segundo numero: ");
	fflush(stdin);
	scanf("%i",&y);
	int div = 0;
	div = x / y;
	
	return div;
}
