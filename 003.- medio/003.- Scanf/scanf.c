/*
	int scanf(const char *format,argumento[,argimentos]);
	
	el string formato es la cadena de control que indica los datos a leer.
	Dicha cadena de control de tres clases de caracteres
	
	* especificadores de formato
	* Caracteres espacios en blanco
	* Caracteres que no sean espacios en blanco
	
	especificacion de formato
	%[*][anco][F/N/L/h/l]tipo
	
	Los especificadores de formato estan precedido del simbolo %, y dicen a la funcion que
	tipo de datos van a ser leidos a continuacion. Los especificadores de formato validos son
	
	%c	->	leer caracter
	%s	->	leer cadena de caracteres
	%i	->	leer entero decimal
	%d	->	leer entero decimal
	%f	->	leer un numero flotante
	%e	->	leer un numero flotante
	%o	->	leer un octal
	%x	->	leer un numero hexadecimal
	%p	->	leer un puntero
	%n	->	recibir un numero igual al numero de caracteres leidos
	%u	->	leer un entero sin signo
	
	Ademas es posible utilizar los modificadores 'h' (short), 'l/L' (long)
	El modificador h se puede aplicar a los tipo de datos d, i, c, u y x, e indica
	que el tipo de dato es un short int o unsigned short int segun el caso.
	El modificador l,L se puede aplicar a los casos anteriores, inficando que los
	que el tipo de dato es un long int, unsigned long int, pero ademas se puede aplicar
	a los tipo de datos e, f y g, e indica que el tipo de dato es un long double
	
	**Un caracter que no sea espacio en blanco en lugar de que scanf() lea y elimine
	el caracter asociado. Por ejemplo %i:%i da lugar a que scanf() lea primero un int
	despues lea y descarte los dos puntos y luego lea el otro int. Si el caracter especificado no se
	encuentra, scanf() termina su ejecucion.
*/

#include <stdio.h>
int main(int argc,char **argv) {
	int x,y;
	char c;
	int cont;
	float f;double d;
	cont = scanf("%i",&x);fflush(stdin);
	printf("Valor de x: entero -> %i\n",x);
	printf("Valor de x: hexadecimal -> %X\n",x);
	printf("Valor de x: octal -> %o\n",x);
	printf("Valor de x: direccion de memoria -> %p\n",&x);
	printf("retorno de scanf -> %i",cont);
	cont = scanf("%i,%i",&x,&y);
	printf("Valor de x: entero -> %i , Valor de y: entero -> %i\n",x,y);
	printf("Valor de x: octal -> %o , Valor de y: octal -> %o\n",x,y);
	printf("Valor de x: hexadecimal -> %X , Valor de y: hexadecimal -> %X\n",x,y);
	printf("Valor de x: direccion de memoria -> %p , Valor de y: direccion de memoria -> %p\n",&x,&y);
	cont = scanf("%f %d",&d,&f);
	printf("Valor de f: float -> %f, Valor de d: double -> %Lf\n",f,d);
	printf("Valor de f: notacion cientifica -> %e, Valor de d: notacion cientifica -> %e\n",f,d);
	printf("Valor de f: a -> %a, Valor de d: a -> %a",f,d);
	return 0;
}
