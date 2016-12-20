/*Calcula el area de un trapecio*/

#include<stdio.h>

int main() {
	float base_M, base_m, altura, area;
	printf("Digite la base menor: ");
	fflush(stdin);
	scanf("%f",&base_m);
	if(base_m < 0) {
		printf("No existen longitudes negativas\n");
		while(base_m < 0){
			printf("Digite la base menor, procure que sea mayor a 0: ");
			fflush(stdin);
			scanf("%f",&base_m);
		}
	}
	
	printf("Digita la base mayor: ");
	fflush(stdin);
	scanf("%f",&base_M);
	if(base_M < base_m) {
		printf("La base mayor no puede ser menor que la base menor\n");
		while(base_M < base_m) {
			printf("Digite nuevamente la base Mayor, procure que sea mas grande que la base menor: ");
			fflush(stdin);
			scanf("%f",&base_M);
		}
	}
	
	printf("Digite la altura: ");
	fflush(stdin);
	scanf("%f",&altura);
	if(altura < 0) {
		printf("No existen longitudes negativas\n");
		while(altura < 0) {
			printf("Digite nuevamente la altura: ");
			fflush(stdin);
			scanf("%f",&altura);
		}
	}
	
	area = ((base_M+base_m)*altura)/2;
	
	printf("El area del trapecio es: %.1f",area);
	
}










