/*
	Punto de silla: es el menor de su fila y el mayor de su columna
*/

#include <stdio.h>
#include <time.h>

int main(int argc,char **argv) {
	int f,c,aux,i,j,matriz[10][20];srand(time(NULL));
	for (f = 0; f < 10; f++) {
		for (c = 0; c < 20; c++) {
			matriz[f][c] = 1 + rand() % ((1000 + 1) - 1);
			printf("matriz[%i][%i] = %i\n",f,c,matriz[f][c]);
		}
	}
	
	
	return 0;
}
