/*
	**Reservar memoria para un arreglo de 5 números, rellenarlo con números que digite
	el usuario, luego utilizar realloc para ampliar ese arreglo a 10 números y agregar 5 números más, 
	por ultimo imprimir el arreglo resultante de 10 números.
*/

#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int *n = (int *)malloc(sizeof(int)*6);
	int i;
	for(i = 0; i < 6; i++)
	{
		fprintf(stdout,"%i) Digite un numero: ",i+1);
		scanf("%i",&n[i]);
	}
	fprintf(stdout,"\n");
	for(i = 0; i < 6; i++)
	{
		fprintf(stdout,"%i)\t%i\n",i+1,n[i]);
	}
	fprintf(stdout,"\n");
	void *nuevo_n = realloc(n,sizeof(int)*11);
	n = (int *)nuevo_n;
	
	for(i = 6; i < 11; i++)
	{
		fprintf(stdout,"%i) Digite un numero: ",i+1);
		fflush(stdin);
		scanf("%i",&n[i]);
	}
	
	fprintf(stdout,"\n");
	for(i = 0; i < 11; i++)
	{
		fprintf(stdout,"%i)\t%i\n",i+1,n[i]);
	}
	system("pause");
	return 0;
}
