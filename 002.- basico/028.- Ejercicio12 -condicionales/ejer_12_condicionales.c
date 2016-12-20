/*Seleccionar un tipo de vehiculo e indicar el peaje a pagar segun un valor numerico 

1 - turismo-> peaje: $500;
2 - autobus-> peaje: $3000;
3 - motocicleta-> peaje: $300;
caso contrario veiculo no autorizadp
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
	int tipo,precio;
	puts("digite '1' para turismo");
	puts("digite '2' por autobud");
	puts("digite '3' por motocicleta");
	printf("Digite el tipo de vehiculo: ");
	fflush(stdin);
	scanf("%i",&tipo);
	
	switch(tipo) {
		case 1:
			precio = 500;
			printf("El precio por turismo es: \$%i",precio);
			break;
		case 2:
			precio = 3000;
			printf("El preio por autobus es: \$%i",precio);
			break;
		case 3:
			precio = 300;
			printf("El precio por motocicleta es \$%i",precio);
			break;
		default:
			puts("Vehiculo no autorizado");
	}

	
	
	
	return 0;
}
