/*
	**Arreglo unidimensional / arrays; 
	
		Array de enteros
		Array flotantes
		Array de caracteres
		Array de string
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	//Array de enteros
	int i,a[] = {10,5,1,3,4};
	
	for(i = 0; i < 5;i++)
	{
		if(i == 5-1) printf("%i",a[i]);
		else printf("%i, ",a[i]);	
	}
	

	//Array de flotantes
	float b[5];
	printf("\n");
	for(i = 0; i < 5; i++)
	{
		printf("Digite el numero %i: ",i+1);
		fflush(stdin);
		scanf("%f",&b[i]);
	}
	
	for(i = 0; i < 5; i++)
	{
		if(i != 5-1) printf("%+.1f, ",b[i]);
		else printf("%+.1f.",b[i]);
	}
	
	//Array de caracteres
	char c[5] = {'a','e','i','o','u'};
	printf("\n");
	for(i = 0; i < 5; i++)
	{
		if(i != 5-1) printf("%c, ",c[i]);
		else printf("%c",c[i]);
	}
	
	//Array de string
	char d[20];
	printf("\nDigite su nombre: ");
	fflush(stdin);
	gets(d);
	printf("%s",d);
	
	getch();
	return 0;
}
