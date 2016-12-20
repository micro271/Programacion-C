//Hacer un programa que haga la media aritmetica de 2 numeros.(con funcion)


#include<stdio.h>
int mediaA(int x, int y);
int main()
{
	int x, y;
	printf("Ingrese 2 digitos separados por espacios:  ");
	fflush(stdin);
	scanf("%i %i",&x,&y);
	printf("La media aritmetica de %i y %i es: %i",x,y,mediaA(x,y));
	return 0;
}

int mediaA(int x,int y)
{
	int resp;
	resp = (x+y)/2;
	return resp;
}
