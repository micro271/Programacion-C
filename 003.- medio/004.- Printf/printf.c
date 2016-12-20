/*
	Printf es una funcion que permite escribir cualquier tipo de dato
	en pantalla:
	
			int printf(const char *formato[,arguments,...]);
		
	El valor que debuelve la funcion es el numero de caracteres impresos.
	La cadena apuntada por formato consta de dos tipos de elementos.El primero
	tipo esta constituido por los caracteres que seran impresos en pantalla, el segundo
	tipo contiene las ordenes de formato que describe la forma en que se muestran los 
	argumentos. Las ordenes de formato estan precedidas del simbolo ' % ' y les sigue
	el codigo de formato. Por cada orden de formato, debe tener un argumento.
	Las ordenes de formato son:
	
											input
	%			simbolo %					printf( "%%" );			%
	%i,%d		int							printf( "%i", 10 );		10
	%u			unsigned int				printf( "%u", 10 );		10	
	%o			octal						printf( "%o", 17 );		21
	%x			hexadecimal					printf( "%x", 17 );		1a
	%X			hexadecimal					printf( "%X", 17 );		1A
	%f,%F		double,float				printf( "%F", 3.14 );	3.1400000
	%e,%E		double,float				printf( "%e", 3.14 );	3.1400000+e+001
	%g,%G		double,float				printf( "%g", 0.0314 );	3.14+e-002
	%a,%A		double						printf( "%a", 31.0 );	0x1.fp+0
	%c			int,char					printf( "%c", 65 );		a
	%s			char(array)					printf( "%s", "HELLO" );HELLO
	%p			&							printf( "%p",3.14 );	000000000F32
	
	especificador de formato
	%[flag][ancho][.precision][F/N/L/h/l]tipo
	
	ancho: La cantidad de caracteres que se imprimiran de la variable especificada. En caso de que la variable
	tenga menos caracteres que el ancho asignados esta la llenara imprimiento espacios al principio de la imprecion
	en pantalla
		
		ejm:						salida
		printf("|%10i|",1);			|         1|
		printf("|%7s|","HELLO");	|  HELLO|
		printf("|%-7s|","HELLO");	|HELLO  |
		
	floag: Son simbolos que se utilizan para dar un formato de salida a los argumentos.
	Pueden aparecer en cualquier orden y son los siguientes:
	
	flag		descripcion										salida									salida
	-			Justificar a la izquierda la salida				printf( "|%5i| |%-5i| ",12,12 );		|   12| |12   |
	+			Incluye el + en los valores positivos			printf( "%+i", 19 );					+19;
	space		Inclute espacios en valores positivos			printf( "|% i|", 19 );					| 19|
	#			Para "%#o", incluye ceros
				Para "%#X" incluye '0X'							pritnf( "%#X", 26 );					0X1A
	0			Llena con ceros la salida						printf( "|%04i|", 12 );					|0012|
	
	precision: Indica el numero de digitos en la parte decimal utilizadas para desplegar la salida.
	La precision por default es 6
	
		ejmp:	printf("|%8.2f|",3.1416);			|    3.14|
		
		Cuando la precision es usada en valores enteros, especificada el minimo de digitos a imprimir
		y el entero es menor a la cantidad especificada los espacios vacios se colocan 0
			
			ejmp:							salida
			printf("|%-10.3i|",7);			|007       |
		
		Cuando se utilizan en cadenas, se utilizan para indicar el numero de caracteres
		que se desplegaran. Si la cadena es mas larga se truncara.
		
			ejmp:							salida
			printf("|%10.3s|","HELLO");		|       HEL|
			printf("|%-5.2s|","HELLO");		|HE   |
			
			
	MODIFICADORES DE LONGITUd [F/N/L/h/l]
	Tal y como lo indica su nombre, se utiliza para modificar la longitud del argumento
	al momento de realizar la salida de la informacion. Son raramente utilizados para los
	tipos int y double; sin embargo para los demas tipos, como long; si es comun utilizarlo.
	Deben de ser adecuadamente utilizados con los tipos de datos adecuados; ya que el uso
	de alguna combinacion pueden producirce funcionamiento impredecible
	
	A continuacion la tabla de modificadores de longitud
	
*/
#include <limits.h>
#include <stdio.h>
int main(int argc,char **argv) {
	printf("1. ORDENES DE FORMATO\n");
	printf("int(%%i)\t\t\t-> %i\n",7);
	printf("int(%%d)\t\t\t-> %d\n",7);
	printf("char(%%c)\t\t-> %c\n",65);
	printf("double(%%f)\t\t-> %f\n",3.1416);
	printf("double(%%e)\t\t-> %e\n",193.14);
	printf("double(%%g)\t\t-> %g\n",3.1416);
	printf("float(%%f)\t\t-> %f\n",3.1416);
	printf("float(%%e)\t\t-> %e\n",314.16);
	printf("float(%%g)\t\t-> %g\n",3.1416);
	printf("char(%%c)\t\t-> %c\n",65);
	printf("char(%%i)\t\t-> %i\n",65);
	printf("char(%%d)\t\t-> %d\n",65);
	printf("char(%%s)\t\t-> %s\n","HELLO WOLD!!!");
	printf("&(%%p)\t\t\t-> %p\n",65);
	
	printf("\n\n2. ESPECIFICADOR DE FORMATO\n");
	printf("|%%5i|\t\t-> |%5i|\n",7);
	printf("|%%-5i|\t\t-> |%-5i|\n",7);
	printf("|%%+i|\t\t-> |%+i|\n",7);
	printf("|%% i|\t\t-> |% i|\n",7);
	printf("|%%#X|\t\t-> |%#X|\n",26);
	printf("|%%#o|\t\t-> |%#o|\n",26);
	printf("|%%05i|\t\t-> |%05i|\n",26);
	
	
	printf("\n\n3. Ancho\n");
	printf("|%%20s|\t-> |%20s|\n","HELLO WORD");
	printf("|%%-20s|\t-> |%-20s|\n","HELLO WORD");
	printf("|%%20i|\t-> |%20i|\n",7);
	printf("|%%-20i|\t-> |%-20i|\n",7);
	printf("|%%-20i|\t-> |%020i|\n",7);
	
	printf("\n\n4. Precision\n");
	printf("|%%.2s|\t\t-> |%.2s|\n","HELLO");
	printf("|%%.2f|\t\t-> |%.2f|\n",3.1416);
	printf("|%%.4f|\t\t-> |%.4f|\n",3.1416);
	printf("|%%10.2s|\t-> |%10.2s|\n","HELLO");
	printf("|%%20.2f|\t-> |%20.2f|\n",3.1416);
	printf("|%%-20.2f|\t-> |%-20.2f|\n",3.1416);
	printf("|%%.3i|\t\t-> |%.3i|\n",1);
	printf("|%%9.6s|\t-> |%9.6s|\n","HELLO WORLD");
	return 0;
}


