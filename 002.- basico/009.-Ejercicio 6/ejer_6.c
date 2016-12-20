//Una tienda ofrece un descuento del 15% sobre el total de la compra y un cliente decea saber
//cuando debera pagar al finalizar la compra

#include <stdio.h>

int main() {
	float precio,desc,sale,precio_final;
	printf("Ingrese el precio total de los productor: ");
	fflush(stdin);
	scanf("%f",&precio);
	
	if(precio < 0) {
		printf("\nPrecio negativo\n");
		while(precio < 0) {
			printf("Ingrese el precio: ");
			fflush(stdin);
			scanf("%f",&precio);
		}
		
	}
	
	printf("Ingrese el descuento: ");
	fflush(stdin);
	scanf("%f",&desc);
	if(desc < 0) desc *= (-1);
	
	sale = (desc*precio)/100;
	precio_final = precio - sale;
	printf("El precio final es de: %.1f",precio_final);
	return 0;
}
