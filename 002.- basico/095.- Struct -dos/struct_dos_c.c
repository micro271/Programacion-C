/*
	**estructuras en c
*/
#include<stdio.h>
#include<stdlib.h>
struct persona{
	char nombre[30];
	int edad;
}
p1 = {"Manuel Zelaya",21},
p2 = {"Matias Zelaya",20},p3;//Esto no es recomendado ya que aletarga el programa al ser una variable global.


int main()
{
	printf("El Se�or %s tienen %i a�os\n",p1.nombre,p1.edad);
	printf("El se�or %s tienen %i a�os\n",p2.nombre,p2.edad);
	
	printf("Digite un nombre: ");
	fflush(stdin);
	gets(p3.nombre);
	printf("Digite su edad: ");
	scanf("%i",&p3.edad);
	
	printf("El se�or %s tiene %i a�os\n",p3.nombre,p3.edad);
	
	system("pause");
	return 0;
}
