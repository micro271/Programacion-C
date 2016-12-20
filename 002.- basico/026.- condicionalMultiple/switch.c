/*
	** Condicional switch : la condicional solo puede contener un dato tipo int o char
	
	switch(int or char){
		case etiqueta1: sentencia1; break;
		case etiqueta2: sentencia2; break;
		case etiqueta3: sentencia3; break;
		case etiqueta4: sentencia4; break;
		default: sentencia;
	}
*/

//ejemplo de numero
#include<stdio.h>

int main() {
	int numero;
	printf("Digite un numero entre (1-3): ");
	fflush(stdin);
	scanf("%i",&numero);
	
	switch(numero) {
		case 1:
			printf("Es el numero 1"); 
			break;
		case 2:
			printf("Es el numero 2"); 
			break;
		case 3: 
			printf("Es el numero 3");
			break;
		default:
			printf("No a digitado un numero correcto");
	}	
	return 0;
}


