#include<stdio.h>

struct contacto
{
	char nombre[40];
	char direccion[80];
	int edad;
	long telefono;
};

typedef struct contacto contacto_t;

int main(void)
{
	int x;
	contacto_t c1;
	printf("Ingrese el nombre: ");
	fflush(stdin);
	gets(c1.nombre);
	
	printf("\nIngrese la direccion: ");
	fflush(stdin);
	gets(c1.direccion);
	
	printf("\nIngrese la edad: ");
	fflush(stdin);
	scanf("%d",&c1.edad);
	
	printf("\nIngrese el telefono: ");
	fflush(stdin);
	scanf("%d\n",&c1.telefono);
	
	printf("Nombre: %s, edad: %i, telefono: %d",c1.nombre,c1.edad,c1.telefono);
	return 0;
}
