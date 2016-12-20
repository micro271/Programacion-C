#include <stdio.h>

int main(void)
{
	int a;
	printf("Ingresa un valor: ");
	fflush(stdin);
	scanf("%i",&a);
	fflush(stdin);
	
	if(a%2 == 0) printf("El numero es par");
	else printf("el numero es impar");
	
	return 0;
}
