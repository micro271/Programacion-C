/*Una distribuidora de motocicletas tiene una promocion de fin de año que consiste en lo siguiente.
Las motos marca Honda  tienen un descuento del 5%, las marca, yamaha tiene el 8% suzuki el 10% y las restantes 2%*/

#include<stdio.h>
#include<string.h>

int main() {
	char marca[10];
	float precio,descuento,precio_final;
	
	printf("Ingrese la marca de su futura motocicleta: ");
	fflush(stdin);
	gets(marca);
	do{
		printf("Ingrese el precio: ");
		fflush(stdin);
		scanf("%f",&precio);
	}while(precio < 0);
	

	if(strcmp(marca,"honda") == 0) {
		descuento = (5*precio)/100;
		precio_final = descuento - precio;
		printf("Tu motocicleta de precio: %.1f marca: %s con su respectivo descuento te costada: %.1f",precio,marca,precio_final);
	}
	else if(strcmp(marca,"yamaha") == 0) {
		descuento = (8 * precio)/100;
		precio_final = precio - descuento;
		printf("Tu motocicleta de precio: %.1f marca: %s con su respectivo descuento te costada: %.1f",precio,marca,precio_final);
	}
	else if(strcmp(marca,"suzuki") == 0) {
		descuento = (10 * precio)/100;
		precio_final = precio - descuento;
		printf("Tu motocicleta de precio: %.1f marca: %s con su respectivo descuento te costada: %.1f",precio,marca,precio_final);
	}
	else {
		descuento = (1 * precio)/100;
		precio_final = precio - descuento;
		printf("Tu motocicleta de precio: %.1f marca: %s con su respectivo descuento te costada: %.1f",precio,marca,precio_final);
	}
	
	return 0;
}
