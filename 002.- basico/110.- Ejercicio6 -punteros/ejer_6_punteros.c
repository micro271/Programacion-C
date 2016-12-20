/*
	Rellenar un array de 10 números, posteriormente utilizando punteros indicar cuales son números pares 
	y su posición en memoria
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char * par_impar(int num);
int main(void)
{
	
	srand(time(NULL));
	int num[10],x,i;
	for(i = 0; i < 10; i++)
	{
		x = 1 + rand() % ((1000 + 1) - 1);
		num[i] = x;
	}
	for(i = 0; i < 10; i++)
	{
		printf("\nEl numero %i\t-> %s\n",num[i],par_impar(num[i]));
	}
	system("pause");
	return 0;
}

char * par_impar(int num)
{
	char * impar = "El numero es impar";
	char * par = "El numero es par";
	
	if(num%2 == 0)
	{
		return par;
	}
	else if(num % 2 != 0)
	{
		return impar;	
	}
}
