/*Hacer dos arrays de cadena de caracteres , pedir el nombre al usuario, guardarlo dentro de un array y luego 
copiar el contenido de ese array en otro*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void copiar_nombre(char * nombre,char * nombre_copiado);

int main()
{
	char nombre[20],nombre_copiado[20];
	
	printf("Digite su nombre: ");
	fflush(stdin);
	scanf("%[^\n]c",&nombre);
	
	copiar_nombre(&nombre[0],&nombre_copiado[0]);
	
	printf("%s",nombre);
	printf("\n%s",nombre_copiado);
}

void copiar_nombre(char * nombre,char *nombre_copiado)
{
	int i = 0;
	while(nombre[i] != '\0')
	{
		nombre_copiado[i] = nombre[i];
		i++;
	}
}
