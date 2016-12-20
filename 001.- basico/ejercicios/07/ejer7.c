#include<stdio.h>

int main(void)
{
	int x,y,z;
	int i;
	printf("Ingrese la longitud de los lados del triangulo separados por enter: \n");
	fflush(stdin);
	scanf("%d\n%d\n%d",&z,&y,&z);
	fflush(stdin);
	
	printf("Los lados del triangulo que elegiste son %d, %d, %d \n",z,y,z);
	
	if(x == z && z == y && y == x)
	{
		printf("Es un triangulo equilatero");
	}
	else if(x!=z && x!=y && z!=y)
	{
		printf("Es un triangulo escaleno");
	}
	else printf("Es un triangulo isosceles");
	
	return 0;
}
