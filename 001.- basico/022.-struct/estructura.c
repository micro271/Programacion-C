#include <stdio.h>
#include <string.h>

struct alumno
{
	int nota;
	char nombre[40];
	int edad;
};

int main(void)
{
	int x;
	struct alumno a1;
	a1.nota = 4;
	printf("La nota es: %i\n",a1.nota);
	a1.edad = 20;
	printf("edad: %d\n",a1.edad);
	char nombre_1[] = "Manuel Zelaya";
	strcpy(a1.nombre,nombre_1);
	printf("%s\n",a1.nombre);
	
	struct alumno a2;
	a2.nota = 8;
	a2.edad = 21;
	char nombre_2[] = "Romina zelaya";
	strcpy(a2.nombre,nombre_2);
	
	printf("Alumno 2, nombre: %s, edad: %i, nota: %i",a2.nombre,a2.edad,a2.nota);
	return 0;
}
