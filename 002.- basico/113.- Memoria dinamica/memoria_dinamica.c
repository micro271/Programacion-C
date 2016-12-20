/*
	Uso de malloc
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	//Int
	int * a;
	a = (int *) malloc(sizeof(int)); //guarda espacio suficiente para que entre un entero
	if(a == NULL)
	{
		fprintf(stdout,"No pudo guardarse correctamente un espacio en memoria para la variable a\n");
	}
	else
	{
		fprintf(stdout,"Si hay espacio en memoria\n");
		*a = 10;
		fprintf(stdout,"%i\n",*a);
	}
	//Float
	float * n;
	n = (float *) malloc(sizeof(float)); //guarda espacio suficiente para que entre un entero
	if(n == NULL)
	{
		fprintf(stdout,"No pudo guardarse correctamente un espacio en memoria para la variable 'n'\n");
	}
	else
	{
		fprintf(stdout,"Si hay espacio en memoria pudo guardarse la variable 'n' correctamente\n");
		*n = 3.1416;
		fprintf(stdout,"%.2f\n",*n);
	}
	char * m;
	m = (char *) malloc(sizeof(char)); //guarda espacio suficiente para que entre un entero
	if(m == NULL)
	{
		fprintf(stdout,"No pudo guardarse correctamente un espacio en memoria para la variable ''m'\n");
	}
	else
	{
		fprintf(stdout,"Se guardo exitosamente la variable 'm' en la memoria dinamica\n");
		*m = 'Z';
		fprintf(stdout,"%c\n\n",*m);
		system("pause");
	}
	return 0;
}
