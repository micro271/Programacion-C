/*Dada la nota en un examen vamos a tener que hacer mediante un codigo escribir el literal que le correspondea cada nota

A - exelente;
B - notable;
C - aprobado;
D y F - reprobado;
*/

#include<stdio.h>
#include<ctype.h>

int main () {
	char nota;
	printf("Digite su nota: ");
	fflush(stdin);
	scanf("%c",&nota);
	nota = toupper( nota );
	switch(nota) {
		case 'A':
			printf("Exelente");
			break;
		case 'B':
			printf("Notable");
			break;
		case 'C':
			printf("Aprobado");
			break;
		case 'D':
		case 'F':
			printf("Reprobado");
			break;
		default:
			printf("te equibocaste de nota");
	}
	return 0;
}
