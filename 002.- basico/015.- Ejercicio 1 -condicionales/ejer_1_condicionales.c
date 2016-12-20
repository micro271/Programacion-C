/*Comprobar si un alumno aprobo o no un examen (aprueba si su nota es mayor a 10.5)*/
#include<stdio.h>

int main() {
	float nota;
	do{
		printf("Ingresa tu nota: ");
		fflush(stdin);
		scanf("%f",&nota);
	}while(nota > 100 || nota < 0);
	if(nota > 10.5) printf("Estas aprobado :D");
	else printf("Estas desaprobado :C!");
	return 0;
}
