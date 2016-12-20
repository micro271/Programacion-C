//Directiva del pre-procesador y variables;
// **Directiva del pre-prosesador: contiene lo que son las librerias y las macros
#include<stdio.h>
/*
	libreria: stdio.h nos sirve para imprimir cosas por pantalla y pedirle al usuario que nos digite cualquier dato
	es la cabecera estandar de nuestra salida de datos 'stdio.h'(standar input output.header).
		Toda libreria comienza con un #include y va entre '<>' */
	
//Otros ejemplos de librerias:
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*
	**Macros: Son para definir una variabl que usaremos a lo largo del programa.
		Toda macro empieza con un #defined luego su identificador y luego su valor*/
		
#define PI 3.1416
int y = 6; //Variables global
int main() {
	//Variable es una posicion de memoria a la cual le asignaremos un valor
	int x = 10; //variable local
	float suma = 0;
	
	suma = PI + x;
	
	printf("La suma de PI y x es: %.3f",suma);
	return 0;
}










