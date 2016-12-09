/*
	Considerando una matriz de 3x3, llenarla con numeros aleatorios entre 1 y 1. Mostrar la matriz y 
	mostrar su determinante
*/

#include <stdio.h>
#include <time.h>

int main(int argc,char **argv) {
	int i,j,k,c,matrizP[3][3],matrizAUX[3][5],det = 0,mult = 1;
	srand(time(NULL));
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			matrizP[i][j] = 1 + rand() % ((10 + 1) - 1);
			matrizAUX[i][j] = matrizP[i][j];
			printf("matrizP[%i][%i]\t: %i\n",i,j,matrizP[i][j]);
		}
	}
	printf("\n");
	for(i = 0; i < 3; i++) {
		for(j = 3; j < 5; j++) {
			matrizAUX[i][j] = matrizP[i][j-3];
			printf("matrizP[%i][%i]\t: %i\n",i,j,matrizAUX[i][j]);
		}
	}
	for(i = 0; i < 6; i++) {
		j = (i < 3)? 0 : 2;
		k = (i < 3)? i : i-3;
		c = 0;
		while(c++ < 3) {
			mult *= matrizAUX[j][k];
			if(i < 3) {
				j++;
			} else{
				j--;
			}
			k++;
		}
		if(i < 3) {
			det += mult;
		} else{
			det -= mult;
		}
		mult = 1;
	}
	printf("La determinante es: %i\n",det);
	return 0;
}

