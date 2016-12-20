/*
	Hacer una estructura llamada corredor, en la cual se tendran los siguientes miembros, nombre, edad, sexo,
	club, pedir datos al usuario para un corredor, y asignarle una categoria de competencia.
		- Juvenir <= 18
		- Señor <= 40
		- veterano > 40
	posteriormente imprimir todos los datos del corredor incluso su categoria de competencia.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	unsigned int cEdad;
	char nombre[30];
	char sexo[10];
	char club[20];
}corredor;

void pedir();
void imprimir();

int main()
{
	corredor corredor1;
	char preg;
	do
	{
		pedir(&corredor1);
		imprimir(&corredor1);
		do
		{
			printf("\nDecea modificar el formulario (S/N): ");
			fflush(stdin);
			scanf("%c",&preg);
			preg = toupper(preg);
		}while(preg != 'S' && preg != 'N');
	}while(preg != 'N');
	
	if(corredor1.cEdad <= 18)
	{
		printf("Estas en la categoria\t->\tJuvenil\n");	
	}
	else if(corredor1.cEdad <= 40 && corredor1.cEdad > 18)
	{
		printf("Estas en la categoria\t->\tSenior\n");
	}
	else if(corredor1.cEdad > 40 && corredor1.cEdad < 100)
	{
		printf("Estas en la categoria\t->\tVeterano\n");
	}
	system("pause");
	return 0;
}
void pedir(corredor * c)
{
	char sexo[30];
	int i;
	
	printf("\tFormulario de corredor\n");
	
	printf("Nombre y apellido: ");
	fflush(stdin);
	gets((*c).nombre);
	for(i = 0; i < strlen(c->nombre); i++)
	{
		if(i == 0)
		{
			c->nombre[0] = toupper(c->nombre[0]);
		}
		if(c->nombre[i] == ' ')
		{
			c->nombre[i+1] = toupper(c->nombre[i+1]);
		}
		
	}
	do
	{
		printf("Edad: ");
		fflush(stdin);
		scanf("%u",&c->cEdad);
		
		if(c->cEdad < 0)
		{
			printf("No existen edades negativas\n");
		}
		else if(c->cEdad > 100)
		{
			printf("Si sos tan viejo no deberias moverte\n");
		}
	}while(c->cEdad < 0 && c->cEdad > 100);
	
	do
	{
		i = 0;
		printf("Sexo: ");
		fflush(stdin);
		gets(sexo);
		while(sexo[i] != '\0')
		{
			sexo[i] = toupper(sexo[i]);
			c->sexo[i] = sexo[i];
			i++;
		}
		sexo[i] = '\0';
		c->sexo[i] = '\0';
	}while(strcmp(sexo,"MASCULINO") != 0 && strcmp(sexo,"FEMENINO") != 0);
	
	printf("Club: ");
	fflush(stdin);
	gets((*c).club);
}

void imprimir(corredor *c)
{
	printf("Nombre:\t->\t%s\n",c->nombre);
	printf("Sexo:\t->\t%s\n",c->sexo);
	printf("Edad:\t->\t%u\n",c->cEdad);
	printf("Club:\t->\t%s",c->club);
}
