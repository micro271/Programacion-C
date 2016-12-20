/*Comprueve si un numero digitado por el usuario es positivo o negativo*/
#include <stdio.h>

int main() {
	float x;
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%f",&x);
	
	if(x > 0) printf("El numero es positivo");
	else printf("El numero es negativo");
}
