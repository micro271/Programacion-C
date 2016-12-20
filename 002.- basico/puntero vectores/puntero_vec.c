#include<stdio.h>
#include<stdlib.h>

void imprimir(int *lambda, const unsigned int cantidad);
void cambiar(int *epsilon);
int main()
{
	unsigned int cantidad,i;
	fprintf(stdout,"Digite la cantidad de numeros que desea ingresar: ");
	fflush(stdin);
	fscanf(stdin,"%i",&cantidad);
	int phi[cantidad];
	for(i = 0; i < cantidad; i++)
	{
		fprintf(stdout,"Digite el valor de la posicion %i: ",i+1);
		fflush(stdin);
		fscanf(stdin,"%u",&phi[i]);
	}
	imprimir(&phi[0],cantidad);
	system("pause");
	return 0;
}

void imprimir(int *lambda, const unsigned int cantidad)
{
	int i;
	for(i = 0; i < cantidad; i++)
	{
		printf("%i\n",*(lambda+i));
	}
}
