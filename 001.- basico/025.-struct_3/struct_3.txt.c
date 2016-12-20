#include <stdio.h>
#include <string.h>

struct Persona{
	char * nombre;
	char * apellido;
	int edad;
	long telefono;
	char * direccion;
	int salario;
};

typedef struct Persona PX;

void imprimir(PX *persona);

int main()
{
	PX p1 = {"Manuel","Zelaya",21,4367313,"Pje Magayane 100",28000};
	PX p3 = {"Matias","Zelaya",20,4367313,"Alem 120",350000};
	imprimir(&p1);
	imprimir(&p3);
	
	/*					Memoria Dinamica					*/
	PX * p2 = (PX *)malloc(sizeof(PX));
	if(p2 == NULL) printf("No se pudo asignar a la memoria");

	(*p2).nombre = "Matias";
	(*p2).apellido = "Zelaya";
	(*p2).edad = 20;
	p2->telefono = 155940555;
	p2->direccion = "alem 190";
	p2->salario = 30000;
	
	printf("\n%s\n",p2->nombre);
	printf("%s\n",p2->apellido);
	printf("%i\n",p2->edad);
	printf("%li\n",(*p2).telefono);
	printf("%s\n",(*p2).direccion);
	printf("%i\n\n",(*p2).salario);
	
	free(p2);
	printf("\n%s\n",p2->nombre);
	printf("%s\n",p2->apellido);
	printf("%i\n",p2->edad);
	printf("%li\n",p2->telefono);
	printf("%s\n",p2->direccion);
	printf("%i\n",p2->salario);
	return 0;
}

void imprimir(PX *persona)
{
	printf("%s\n",persona->nombre);
	printf("%s\n",persona->apellido);
	printf("%i\n",persona->edad);
	printf("%li\n",(*persona).telefono);
	printf("%s\n",(*persona).direccion);
	printf("%i\n\n",(*persona).salario);
}










