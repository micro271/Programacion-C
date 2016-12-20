/*
	** Pedirle 2 numeros al usuario sumarlos, restarlos, dividirlos y multiplicarlos
*/

#include<stdio.h>

int main() {
	int x,y;
	printf("Ingrese 2 numeros separados por espacios...\n");
	fflush(stdin);
	scanf("%i %i",&x,&y);
	
	int suma = x + y;
	printf("Sumamos los 2 valores -> %i\n",suma);
	
	int resta = x - y;
	printf("Restamos los 2 valores -> %i\n",resta);
	
	int multiplicacion = x * y;
	printf("Multiplicamos los 2 valores -> %i\n",multiplicacion);
	
	int divicion = x / y;
	printf("Dividimos los 2 valores -> %i",divicion);
	return 0;
}
