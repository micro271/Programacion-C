/* Encuentra la hipotenusa pidiendole al usuario los 2 catetos restantes */
#include<stdio.h>
#include<math.h>

int main() {
	float x,y;
	//Cateto x =>
	printf("Ingrese el valor del cateto x y cateto y\n");
	printf("Cateto x: ");
	fflush(stdin);
	scanf("%f",&x);
	if(x < 0) printf("No existen longitudes negativas\n");
	while(x < 0) {
		 printf("cateto x: \n");
		 fflush(stdin);
		 scanf("%f",&x);
	}
	
	//cateto y =>
	printf("Cateto y: ");
	fflush(stdin);
	scanf("%f",&y);
	if(y < 0) printf("No existen longitudes negativas\n");
	while(y < 0) {
		printf("carero y: ");
		fflush(stdin);
		scanf("%f",&y);
	}
	
	float hip = sqrt(pow(x,2)+pow(y,2));
	printf("El valor de la hipotenusa es: %.2f",hip);
	
	return 0;
}
