/*
	**Pedir al usuario el número de elementos para un array de números enteros, posteriormente 
	comprobar con malloc si hay memoria suficiente, si la hay es entonces rellenar ese array con números 
	aleatorios, si no la hay decir que hay un error en la asignación de memoria.
*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	unsigned int largo;
	fprintf(stdout,"Digite la cantidad de elementos: ");
	fflush(stdin);
	scanf("%u",&largo);
	
	long long int *array = (long long int *)malloc(sizeof(long long int)*largo);
	if(array == NULL)
	{
		fprintf(stdout,"Error de asignacion de memoria\n");
	}
	else
	{
		fprintf(stdout,"Se asigno exitosamente la memoria\n");
	}
	
	fprintf(stdout,"long[li]\t-> %i bits\n",sizeof(long));
	fprintf(stdout,"signed long[li]\t-> %i bits\n",sizeof(long int));
	fprintf(stdout,"long int[li]\t-> %i bits\n",sizeof(long int));
	fprintf(stdout,"signed long int[li]\t-> %i bits\n\n",sizeof(long int));
	
	fprintf(stdout,"long long[lli]\t-> %i bits\n",sizeof(long long));
	fprintf(stdout,"signed long long[lli]\t-> %i bits\n",sizeof(long long));
	fprintf(stdout,"long long int[lli]\t-> %i bits\n",sizeof(long long int));
	fprintf(stdout,"signed long long int[lli]\t-> %i bits\n\n",sizeof(long long int));
	
	fprintf(stdout,"unsigned long[lu]\t-> %i bits\n",sizeof(unsigned long));
	fprintf(stdout,"unsigned long long[llu]\t-> %i bits\n",sizeof(unsigned long long));
	system("pause");
	return 0;
}
