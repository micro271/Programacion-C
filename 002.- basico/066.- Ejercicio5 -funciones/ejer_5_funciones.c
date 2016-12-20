/*Mostrar una opciones
	1. celcius a farhenheit
	2. fahrenheit a celsius
	3.celcius a kelvin
*/
#include<stdio.h>
void aFahrenheit(int cels);
void aCelcius(int fahr);
void aKilvin(int kelv);
void menu();

int main()
{
	menu();
	
	return 0;
}
void menu()
{
	int opc;
	int temp;
	printf("\tConvercion de grados\n");
	printf("1. Celcius a fahrenheit\n");
	printf("2. Fahrenheit a celcius\n");
	printf("3. Celcius a kelvin\n");
	printf("Ingrese una opcion: ");
	fflush(stdin);
	scanf("%i",&opc);
	if(opc > 3 || opc < 0)
	{
		printf("Opcion invalida\n");
	}
	while(opc > 3 || opc < 0)
	{
		printf("Ingrese nuevamente una opcion: ");
		fflush(stdin);
		scanf("%i",&opc);
	}
	
	printf("Ingrese una temperatura: ");
	fflush(stdin);
	scanf("%i",&temp);
	
	switch(opc)
	{
		case 1: aFahrenheit(int temp);break;
		case 2: aCelcius(int temp);break;
		case 3: aKelvin(int temp);break;
	}
}


void aFahrenheit(int cels)
{
	int f;
	f = ((9*cels)/5)+32;
	printf("Los grados %i Celcius a Fahrenheit es: %i",cels,f);
}
void aCelcius(int fahr)
{
	i c;
	c = ((fahr-32)*5)/9;
	printf("Los grados %i Fahrenheit a celsius es: %i",fahr,c);
}
void aKelvin(int cels)
{
	int k;
	k = cels + 273.15;
	printf("Los grados %i Celsius a Kelvin es: %i",cels,k);
}
