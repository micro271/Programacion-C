/*Determinar si un numero es par o impar*/

#include <stdio.h>

int main() {
	int x;
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&x);
	if(x % 2 == 0) printf("es par");
	else printf("es impar");
	return 0;
}
