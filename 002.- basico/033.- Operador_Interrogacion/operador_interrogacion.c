/* ** Exprecion condicinal: el operador "?"

Sintaxis:
			Condicion ? Esprecion1 : exprecion2
*/

//numeros pares

#include<stdio.h>

int main()
{
	int x;
	printf("Digite un numero: ");
	fflush(stdin);
	scanf("%i",&x);
	(x%2==0)?printf("El numero es par"):printf("El numero es impar");
	return 0;
}
