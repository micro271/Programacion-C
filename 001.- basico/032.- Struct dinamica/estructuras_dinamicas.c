#include<stdio.h>

typedef struct{
	char * nombre;
	char * apellido;
	int edad;
	long telefono;
}Alumno;

int main()
{
	Alumno a1;
	a1.edad = 20;
	a1.nombre = "Manuel";
	a1.apellido = "Zelaya";
	a1.telefono = 4123123;
	printf("El alumno %s %s tiene la edad: %i",a1.nombre,a1.apellido,a1.edad);
	
	
	Alumno *a2;
	a2 = (Alumno* )malloc(sizeof(Alumno));
	if(a2 == NULL) printf("La memoria esta llena");
	(*a2).edad = 30;
	a2->nombre = "Matias";
	a2->apellido = "Zelaya";
	a2->telefono = 123123;
	
	printf("\nEl alumno %s %s de edad: %i tiene el telefono: %li",a2->nombre,a2->apellido,(*a2).edad,(*a2).telefono);
	
	free(a2);
	return 0;
}
