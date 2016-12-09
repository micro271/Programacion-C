/*
	considerando 2 vectores de 10 elemento, llenarlo con numeros aleatorios, mostrarlos, sumarlos y guardarlos en un
	tercer vector, mostrar el vector resultante. Se debe hacer utilizando funciones, al menos los 3 siguientes:
	llenarVector, SumarVector y MostrarVector;
*/
#include <stdio.h>
#include <time.h>

void LlenarVector(int *vec,int l);

void SumarVector(int *cont,int *vec1,int *vec2,int l);

void MostrarVector(int *vec,int l,char *nombre);

int main(int argc,char **argv) {
	int vec1[10];
	int vec2[10];
	int suma[10];
	
	LlenarVector(vec1,sizeof(vec1)/sizeof(int));
	MostrarVector(vec1,sizeof(vec1)/sizeof(int),NULL);
	printf("\n");
	
	LlenarVector(vec2,10);
	MostrarVector(vec2,10,NULL);
	printf("\n");
	
	SumarVector(suma,vec1,vec2,10);
	MostrarVector(suma,sizeof(vec1)/sizeof(int),"suma");
	printf("\n");
	return 0;
}

void LlenarVector(int *vec,int l) {
	int i;srand(time(NULL));
	for(i = 0; i < l; i++) {
		vec[i] = 1 + rand() % ((100 + 1) - 1);
	}
}

void SumarVector(int *cont,int *vec1,int *vec2,int l) {
	short int i;
	for(i = 0; i < l; i++) {
		cont[i] = vec1[i] + vec2[i];
	}
}

void MostrarVector(int *vec,int l,char *nombre){
	short int i;
	for(i = 0; i < l; i++) {
		if(nombre != NULL) {
			printf("%s[%i] = %i\n",nombre,i,vec[i]);
		} else {
			printf("vector[%i] = %i\n",i,vec[i]);
		}
	}
	
}
