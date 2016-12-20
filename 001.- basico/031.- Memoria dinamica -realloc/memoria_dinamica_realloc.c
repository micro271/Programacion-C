/*
	**Memoria dinamica
	realloc		->	sirve para modificar el tamaño de los vectores
	
	voir *realloc(void * bloque_anetrior, size_t nuevos_bytes);
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	
	void * vector_dinamico = NULL;
	void *vector_dinamico_6_lugares = NULL;
	vector_dinamico = malloc(4*sizeof(int));
	if(vector_dinamico == NULL) printf("No se pudo almacenar");
	
	int * vector_convertico = NULL;
	vector_convertico = (int *)vector_dinamico;
	vector_convertico[0] = 54;
	vector_convertico[1] = 52;
	vector_convertico[2] = 30;
	vector_convertico[3] = 23;

	vector_dinamico_6_lugares = realloc(vector_dinamico,6*(sizeof(int)));
	if(vector_dinamico_6_lugares == NULL) printf("Error foña 24");
	
	vector_convertico = (int* )vector_dinamico_6_lugares;
	
	vector_convertico[4] = 20;
	vector_convertico[5] = 15;
	printf("El nuevo vector en el [4] %i\n",vector_convertico[4]);
	printf("El nuevo vector en el [5] %i",vector_convertico[5]);
	return 0;
}
