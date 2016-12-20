/*
	Hacer una variable de tipo int, otra de tipo float y por ultimo una de tipo char, 
	almacenar datos en cada una de las variables, posteriormente indicar la posición de memoria 
	donde se encuentran guardados los datos de cada variable. Con punteros.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 10, * p_n = &n;
	float m = 3.1416, * p_m = &m;
	char o = 'Z', * p_o = &o;
	
	printf("\t\tVariable entera\n");
	printf("\tn\t-> %i\n",n);
	printf("\t*p_n\t-> %i\n",*p_n);
	printf("\t&n\t-> %p <- Direccion de memoria exadecimal\n",&n);
	printf("\tp_n\t-> %p <- Direccion de memoria exadecimal\n",p_n);
	
	printf("\n\n\t\tVariable float\n");
	printf("\tm\t-> %.2f\n",m);
	printf("\t*p_m\t-> %.2f\n",*p_m);
	printf("\t&m\t-> %p <- Direccion de memoria exadecimal\n",&m);
	printf("\tp_m\t-> %p <- Direccion de memoria exadecimal\n",p_m);
	
	printf("\n\n\t\tVariable char\n");
	printf("\to\t-> %c\n",o);
	printf("\t*p_o\t-> %c\n",*p_o);
	printf("\t&o\t-> %p <- Direccion de memoria exadecimal\n",&o);
	printf("\tp_o\t-> %p <- Direccion de memoria exadecimal\n",p_o);
	system("pause");
	return 0;
}
