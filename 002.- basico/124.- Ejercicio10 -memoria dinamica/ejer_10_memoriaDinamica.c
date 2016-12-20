/*
	Hacer un puntero array de tipo float, pedir el usuario el número de elementos, luego reservar memoria 
	dinámica con calloc, luego llenar el array, imprimir todos los elementos, y por ultimo liberar el 
	espacio de memoria dinámica utilizado.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
	size_t n_elem;
	fprintf(stdout,"Digite la cantidad de elementos que decea ingresar: ");
	fscanf(stdin,"%u",&n_elem);
	void * n_num = calloc(2,sizeof(float));
	
	float * n = (float* )n_num;
		
	
	

	int j[2] = {121,523};
	int *n_j;
	n_j = &j[0];
	fprintf(stdout,"%.1f, %.1f\n",n[0],n[1]);
	fprintf(stdout,"%i\n",*n_j);
	n_j++;
	fprintf(stdout,"%i\n",*n_j);
	system("pause");
	return 0;
}
