/*Ingresar por el teclado el nombre y signo de cualquier persona  e imprima el nombre solo si la persona es de signo aries,
en caso contrario imprimir no es signo aries */

#include<stdio.h>
/*
	**strcmp(variable,comparacion), primero va la variable que queremos comprar y despues va el string con el que se tiene q
	comparar si son iguales da 0 y si son distintos es 1
*/

int main() {
	char nombre[30],signo[20];
	
	printf("Digite su nombre: ");
	fflush(stdin);
	gets(nombre);
	
	printf("Digite su signo: ");
	fflush(stdin);
	gets(signo);
	
	printf("Resultado del strcmp(comparacion de cadenas): %i\n",strcmp(signo,"aries"));
	
	if(strcmp(signo,"aries") == 0) {
		printf("Es signo aries su nombre es %s",nombre);
	}
	else puts("no es signo aries");
	
	return 0;
}
