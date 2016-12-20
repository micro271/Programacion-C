/* Calcular el perimetro de un circulo */
#include <stdio.h>
#include <math.h>
#define PI 3.14


int main() {
	float r;
	printf("Ingrese el radio: ");
	fflush(stdin);
	scanf("%f",&r);
	//Perimetro
	float p;
	p = (2*r)*PI;
	printf("El perimetro del circulo es: %.1f\n",p);
	
	//Area
	float a;
	a = PI*pow(r,2);
	printf("El area del circulo con r: %.1f es: %.1f\n",r,a);
	
	/*
		** NO!!1 IMPORTA CUANDO TENGA DE RADIO PERIMETRO DIVIDIDO EN DIAMETRO SIEMPRE DA 3.14..
	*/
	float pi;
	pi = (p/(r*2));
	printf("perimetro / diametro = %.2f",pi);
}
