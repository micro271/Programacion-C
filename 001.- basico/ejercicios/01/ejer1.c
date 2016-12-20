#include <stdio.h>

int main(void)
{
	int a,b;
	printf("Ingresa el valor de a: ");
	fflush(stdin);
	scanf("%i",&a);
	fflush(stdin);
	printf("Ingresa el valor de b: ");
	scanf("%i",&b);
	if(a > b) printf("a > b");
	else if(a < b) printf("a < b");
	else printf("a == b");
	return 0;

}
