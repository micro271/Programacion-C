/*
	**Estructura 	-> es una coleccion de 1 o mas tipos de elementos denominados miembros
	que cada uno de los elementos puede ser de distintos tipos.
	El resumen una estructura es una coleccion de elementos;
*/
#include<stdio.h>
#include<stdlib.h>

struct coleccion_cd{
	char titulo[30];
	char artista[30];
	int numCanciones;
	float precio;
	char fecha_compra[30];
}cd1,cd2,cd3; //otra forma de llamar pero no recomendada ya que seran variables globales y aletargaran el prograama


int main()
{
	struct coleccion_cd cd1,cd2,cd3; //declaramos una variable de tipo struct coleccion_cd
	
	/*
		los elementos de tipo struct coleccion_cd como cd1, cd2 y cd3 Contienen todos los elementos que contiene
		la estructura coleccion_cd
	*/
	system("pause");
	return 0;
}










