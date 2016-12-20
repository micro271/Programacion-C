/*Hacer un programa que pida al usuario 3 numeros y los ordene de manera descendente , utilizando un
procedimiento*/

#include<stdio.h>

void descendente(int x, int y, int z);
int main()
{
	int x,y,z;
	printf("Digite el primer numero: ");
	fflush(stdin);
	scanf("%i",&x);
	printf("Digite el segundo numero: ");
	fflush(stdin);
	scanf("%i",&y);
	printf("Digite el tercer numero: ");
	fflush(stdin);
	scanf("%i",&z);
	
	descendente(x,y,z);
	return 0;
}

void descendente(int x, int y, int z)
{
	if(x > y && x > z)
	{
		if(y > z)
		{
			printf("%i %i %i",x,y,z);
		}
		else printf("%i %i %i",x,z,y);
	}
	else if(y > x && y > z)
	{
		if(x > z)
		{
			printf("%i %i %i",y,x,z);
		}
		else printf("%i %i %i",y,z,z);
	}
	else if(z > x && z > y)
	{
		if(x > y)
		{
			printf("%i %i %i",z,x,y);
		}
		else printf("%i %i %i",z,y,x);
	}
	else printf("%i %i %i",x,y,z);
}
