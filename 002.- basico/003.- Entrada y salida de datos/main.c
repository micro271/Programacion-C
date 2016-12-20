//Entrada y salida de datos

#include<stdio.h>
#include<string.h>

int main() {
	//salida de datos
	int suma = 10;
	printf("la suma es: %i\n",suma);
	
	int a = 10;
	float b = 15.5;
	char c = 'e';
	printf("%i, %.1f, %c\n",a,b,c);
	
	//Entrada de datos
	int e;
	float i;
	char o;
	printf("Digite el valor de la variable e(entero): ");
	fflush(stdin);
	scanf("%i",&e);
	printf("El valor de e es %i\n",a);
	
	printf("Digite el valor de la variable i(flotante): ");
	fflush(stdin);
	scanf("%f",&i);
	printf("El valor de la variable i es: %.1f\n",i);
	
	printf("Digite el valor de la variable o(1 solo elemento): ");
	fflush(stdin);
	scanf("%c",&o);
	printf("El valor de la variable o es: %c\n",o);
	
	//Guardamos palabras
	char nombre[50];
	printf("Digite su nombre: ");
	fflush(stdin);
	// scanf("%[^\n]s",&nombre);
	gets(nombre);
	printf("\nSu nombre es: %s",nombre);
	
	return 0;
}




