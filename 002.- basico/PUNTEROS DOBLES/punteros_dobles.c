#include<stdio.h>
#include<stdlib.h>
void caracter(char *str);
typedef int **matriz;
int main(int argc, char **argv)
{
	int i;
	matriz p; // O int **p
	int *p_uno,*p_dos,*p_tres,*p_cuatro,*p_cinco;
	p_uno = (int *)malloc(sizeof(int)*5);
	p_dos = (int *)malloc(sizeof(int)*5);
	p_tres = (int *)malloc(sizeof(int)*5);
	p_cuatro = (int *)malloc(sizeof(int)*5);
	p_cinco = (int *)malloc(sizeof(int)*5);
	for(i = 0; i < 5; i++)
	{
		*(p_uno+i) = i*2;
	}
	for(i = 0; i < 5; i++)
	{
		*(p_dos+i) = i*3;
	}
	for(i = 0; i < 5; i++)
	{
		*(p_tres+i) = i*4;
	}
	for(i = 0; i < 5; i++)
	{
		*(p_cuatro+i) = i*5;
	}
	for(i = 0; i < 5; i++)
	{
		*(p_cinco+i) = i*6;
	}
	
	int **v;
	v = (int **)malloc(sizeof(int *)*5);
	*v = p_uno;
	*(v+1) = p_dos;
	*(v+1) = p_tres;
	*(v+1) = p_cuatro;
	*(v+1) = p_cinco;
	v[0][2] = 20;
	v[0][1] = 30;
	printf("%p\n",&(v[0][2]));
	printf("%i\n",v[0][2]);
	
	printf("\n%p\n",v[0]+1);
	printf("%i\n",v[0][1]);
	
	
	printf("\n%p",*(v+0)+3);
	printf("\n%i\n\n\n",*(*(v+0)+3));
	

	return 0;
}

