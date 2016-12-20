//Arreglo de estructura
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char nombre[30];
	char apellido[30];
	int edad;
	unsigned long telefono;
	char trabajo[20];
}datos_p;

int main()
{
	unsigned int largo;
	do
	{
		printf("Digite la cantidad de personas que decea registrar: ");
		fflush(stdin);
		scanf("%u",&largo);
	}while(largo < 0);
	datos_p p[largo];
	int i;
	for(i = 0; i < largo; i++)
	{
		if(i != 0)
		{
			printf("\n\n");
		}
		printf("%i. nombre: ",i+1);
		fflush(stdin);
		gets(p[i].nombre);
		printf("%i. apellido: ",i+1);
		fflush(stdin);
		gets(p[i].apellido);
		printf("%i . edad: ",i+1);
		fflush(stdin);
		scanf("%i",&p[i].edad);
		printf("%i. Telefono: ",i+1);
		fflush(stdin);
		scanf("%lu",&p[i].telefono,i+1);
		printf("%i. trabajo: ",i+1);
		fflush(stdin);
		gets(p[i].trabajo);
	}
	
	for(i = 0; i < largo; i++)
	{
		printf("%i. el señor %s %s tiene %i anios, su telefono es %lu y trabaja de %s\n",i+1,p[i].nombre,p[i].apellido,p[i].edad,p[i].telefono,p[i].trabajo);
	}
	system("pause");
	return 0;
}
