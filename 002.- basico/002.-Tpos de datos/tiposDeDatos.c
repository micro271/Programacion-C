// Tipos de datos
#include<stdio.h>
/*
	** char : Tipo caracter puede almacenar cualquier cosa sea una letra, numero, simbolo
	** short : numeros pequeños -128 a 127;
	** int : numeros grandes -32768 a 32767;
	** unsigned int : numeros positivos 0..65535;
	** long : numeros muy grandes -2.147.483.648 a 2.147.483.639;
	** float : numeros con coma 1.18e-38 a 3.40e38;
	** double : numeros con coma muy grandes 2.23e-308 a 1.78e108;
*/

int main() {
	char a = 'e'; //Tamaño: 1bytes rango: 0..255;
	short b = -15; //Tamaño: 2bytes rando: -128..127;
	int c = 1024; //tamaño: 2bytes rando: -32768..32767;
	unsigned int d = 128; //tamaño:2bytes rango: 0..65535;
	long e = 894932123; //tamaño 4bytes rango: -2.147.483.648..2.147.483.637;
	long long h = 123123123112312323; // tamaño 8 bytes rango -9e19..9e19;
	float f = 15.678; //tamaño 4bytes rango: 1.18e-38..3.40e38;
	double g = 124213.12314231; // tamaño: 8vytes rango 2.23e-108..1.79e308;
	printf("El elemento de tipo char es: %c \n",a);
	printf("El elemento de tipo short es: %i \n",b);
	printf("El elemento de tipo int es: %i \n",c);
	printf("El elemento del tipo unsigned int es: %i \n",d);
	printf("El elemento de tipo long es: %li\n",e);
	printf("El elemento de tipo long long es: %lli\n",h);
	printf("El elementode tipo float es: %.3f\n",f);
	printf("El elemento de tipo double es: %lf",g);
	
	return 0; 
}
