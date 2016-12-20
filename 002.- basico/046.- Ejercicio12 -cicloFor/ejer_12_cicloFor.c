// serie fibonacci

//1 1 2 3 5 8 13

#include<stdio.h>

int main()
{
	int num,i,x = 0, y = 1, z = 1;
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%i",&num);
	if(num < 0) printf("El numero debe ser un entero\n");
	while(num < 0)
	{
		printf("Ingrese un numero: ");
		fflush(stdin);
		scanf("%i",&num);
	}
	
	for(i = i; i <= num; i++)
	{
		z = x + y;
		x = y;
		y = z;
		
		printf("%i, ",z);
	}	
	
	return 0;
}
