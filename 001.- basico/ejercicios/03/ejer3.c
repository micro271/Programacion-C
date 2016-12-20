#include<stdio.h>

int main(void)
{
	int a,b,c;
	printf("Ingresa el primero valor: ");
	fflush(stdin);
	scanf("%i",&a);
	printf("Ingresa el 2do valor: ");
	fflush(stdin);
	scanf("%i",&b);
	printf("Ingresa el 3er valor: ");
	fflush(stdin);
	scanf("%i",&c);
	
	if(a > b && a > c) printf("%i es el mayor",a);
	else if(b > a && b > c) printf("%i es el mayor",b);
	else if(c > a && c > b) printf("%i es el mayor",c);
	else printf("los 3 son iguales a:%i, b:%i, c:%i",a,b,c);
	return 0;
}
