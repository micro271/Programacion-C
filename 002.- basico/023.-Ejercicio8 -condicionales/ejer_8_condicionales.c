/*Ingresa por teclado el nombre, edad y el sexo de cualquier persona e imprimela, solo si la persona es de sexo masculino
y mayor de edad el nombre de la persona*/

#include<stdio.h>
#include<string.h>
int main() {
	char nombre[50];
	char sexo[10];
	int edad;
	
	do{
		printf("Ingrese su nombre: ");
		fflush(stdin);
		gets(nombre);
	}while(strlen(nombre) < 1);
	
	do{
		printf("Ingrese el sexo: ");
		fflush(stdin);
		gets(sexo);
	}while((strcmp(sexo,"masculino") != 0) && (strcmp(sexo,"femenino") != 0));
	
	do{
		printf("Ingrese su edad: ");
		fflush(stdin);
		scanf("%i",&edad);
	}while(edad < 0 || edad > 150);
	
	if(strcmp(sexo,"masculino") == 0 && edad >= 18) {
		printf("Ud %s es mayor de edad",nombre);
	}
	return 0;
}
