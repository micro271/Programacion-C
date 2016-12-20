//Calcular el mayor de 2 numeros leidos del teclado y visualizado en pantalla

#include<stdio.h>

int main () {
	int x, y;
	printf("Digite dos numeros separados por espacios: ");
	fflush(stdin);
	scanf("%i %i",&x,&y);
	if(x > y) printf("%i > %i",x,y);
	else {
		if(x < y) printf("%i < %i",x,y);
		else printf("%i = %i",x,y);
	}
	return 0;
}
