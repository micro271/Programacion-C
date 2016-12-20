#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int i;
	char nombre[20];
	fflush(stdin);
	fgets(nombre,20,stdin);
	for(i = 0; i < sizeof(nombre); i++) {
		if(nombre[i] == '\n') {nombre[i] = '\0';break;}
	}
	char *desde_que_caracter = (char *)memchr(nombre,'t',strlen(nombre)+1);
	/*
		**memchr(variable,caracter,cuantos leer)
		Esta funcion busca el caracter pedido y si este caracter existe guarda los caracteres que hay a partir de ese paracter
		en caso contrario dicha variable que encierra a la funcion daria un NULL
	*/
	if(desde_que_caracter != NULL)
		printf("%s,%s",nombre,desde_que_caracter);
	else
		printf("Algo salio mal");
	return 0;
}
