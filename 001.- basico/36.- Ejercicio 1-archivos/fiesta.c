#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char nombre[20];
	int edad;
	char sexo[20];
}invitado;
invitado *crear_form_invitado();
invitado *agregar(invitado *inv,int cantidad);
void ask(invitado *inv);
void write(invitado *inv);
void write_all(invitado *inv,int cantidad);

int main(int argc,char** argv)
{
	invitado *inv = NULL;
	inv = crear_form_invitado();
	write(inv);
	return 0;
}

invitado *crear_form_invitado()
{
	invitado *aux;
	aux = (invitado* )malloc(sizeof(invitado));
	return aux;
}
invitado *agregar(invitado *inv,int cantidad)
{
	invitado *aux;
	aux = (invitado* )realloc(inv,sizeof(invitado)*cantidad);
	return aux;
}

void ask(invitado *inv)
{
	printf("Nombre: ");
	fflush(stdin);
	gets(&inv->nombre);
	printf("Edad: ");
	fflush(stdin);
	scanf("%i",&inv->edad);
	printf("Sexo: ");
	fflush(stdin);
	gets(&inv->sexo);
	printf("Se a guardado exitosamente:\n");
	system("pause");
}
void write_all(invitado *inv,int cantidad)
{
	char *archivo = "invitados.txt";
	FILE *archivito = NULL;
	archivito = fopen(archivo,"w");
	int i;
	for(i = 0; i < cantidad; i++)
	{
		printf("Nombre: %s\t\tEdad:%i\tSexo: %s\n",(inv+i)->nombre,(inv+i)->edad,(inv+i)->sexo);
		fprintf(archivito,"Nombre: %s, Edad:%i, Sexo: %s\n",(inv+i)->nombre,(inv+i)->edad,(inv+i)->sexo);
	}
}
void write(invitado *inv)
{
	char quiere;int cantidad = 1, pos = 0;
	do
	{
		ask(inv+pos);
		do
		{
			printf("\nDesea agregar mas invitados (S/N)?: ");
			fflush(stdin);
			scanf("%c",&quiere);
			quiere = tolower(quiere);
		}while(quiere != 's' && quiere != 'n');
		if(quiere == 's')
		{
			cantidad++;
			pos++;
			inv = agregar(inv,cantidad);
		}
	}while(quiere == 's');
	write_all(inv,cantidad);
}
