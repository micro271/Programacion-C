//Hacer un programa que al pulsar 1 se borre la pantalla

#include<stdio.h>
#include<stdlib.h>

int main() {
	char tecla;
	puts("\t--------------------------------");
	puts("\t--------------------------------");
	puts("\t--------------------------------");
	puts("\t--------------------------------");
	puts("\tPorgrama de borrado de pantalla");
	puts("\t--------------------------------");
	puts("\t--------------------------------");
	puts("\t--------------------------------");
	puts("\t--------------------------------");
	printf("Digite el numero 1: ");
	fflush(stdin);
	scanf("%c",&tecla);
	
	if(tecla == '1') {
		system("cls");
		puts("A funcionado el limpiado de pantalla");
	}
	else puts("no a funcionado el limpiado");
	return 0;
}
