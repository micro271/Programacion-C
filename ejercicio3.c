/*
	Considerar un vector de 10 elementos llenar con numeros aleatorios del 1 al 100, mostrar el vector, calcular
	la media y mostrarla, mostrar los elementos arriba de la media
*/

#include <stdio.h>
#include <time.h>
int main(int argc,char **argv) {
	int vector[10],i;
	float media = 0.;srand(time(NULL));
	for(i = 0; i < 10; i++) {
		vector[i] = 1 + rand() % ((100 + 1) - 1);
		media += vector[i];
		printf("vector[%i]\t: %i\n",i,vector[i]);
	}
	media /= 10;
	printf("\nElementos mayores a la media aritmetica = %.2f\n",media);
	
	for(i = 0; i < 10; i++) {
		if(vector[i] > media) {
			printf("vector[%i]\t: %i\n",i,vector[i]);
		}
	}
	return 0;
}
