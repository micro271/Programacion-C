#include <stdio.h>
#include <limits.h>
int main(int argc,char **argv) {
	char xChar;
	int xInt;
	float xFloat;
	double xDouble;
	long int xLongi;
	xChar = 65;
	xInt = 391;
	xFloat = 3.1416;
	xDouble = 2.71;
	xLongi = LONG_MAX;
	
	char *pChar = &xChar;
	int *pInt;
	float *pFloat;
	double *pDouble;
	long int *pLongi = &xLongi;
	void *pVoid;
	
	pInt = &xInt;
	pFloat = &xFloat;
	pDouble = &xDouble;
	pVoid = &xInt;
	
	printf("Longitud en bytes de los apuntadores\n");
	printf("sizeof pChar\t= %i\n",sizeof(pChar));
	printf("sizeof pInt\t= %i\n",sizeof(pInt));
	printf("sizeof pLongi\t= %i\n",sizeof(pLongi));
	printf("sizeof pFloat\t= %i\n",sizeof(pFloat));
	printf("sizeof pDouble\t= %i\n",sizeof(pDouble));
	printf("sizeof pVoid\t= %i\n",sizeof(pVoid));
	
	printf("\nDesplegando la direccion de memoria de las variables\n");
	printf("Direccion de memoria de xChar\t: %p - %u - %X\n",&xChar,&xChar,&xChar);
	printf("Direccion de memoria de xInt\t: %p - %u - %X\n",&xInt,&xInt,&xInt);
	printf("Direccion de memoria de pLongi\t: %p - %u - %X\n",&xLongi,&xLongi,&xLongi);
	printf("Direccion de memoria de xFloar\t: %p - %u - %X\n",&xFloat,&xFloat,&xFloat);
	printf("Direccion de memoria de xDouble\t: %p - %u - %X\n",&xDouble,&xDouble,&xDouble);
	
	printf("\nDesplegamos la direccion de memoria de los apuntadores y a que aputan\n");
	printf("Direccion de memoria pChar\t: %p - Donde apunta pChar\t: %p\n",&pChar,pChar);
	printf("Direccion de memoria de pInt\t: %p - Donde apunta pInt\t: %p\n",&pInt,pInt);
	printf("Direccion de memoria de pLongi\t: %p - Donde apunta pLongi: %p\n",&pLongi,pLongi);
	printf("Direccion de memoria de pFloar\t: %p - Donde apunta pFloar: %p\n",&pFloat,pFloat);
	printf("Direccion de memotia de pDouble\t: %p - Donde apunta pDouble: %p\n",&pDouble,pDouble);
	printf("Direccion de memoria de pVoid\t: %p - Donde apunta pVoid\t: %p\n",&pVoid,pVoid);
	
	printf("\nDesplegar los valores que apuntan los apuntadores\n");
	printf("Valor de pChar\t: %c\n",*pChar);
	printf("Valor de pInt\t: %i\n",*pInt);
	printf("Valor de pLongi\t: %li\n",*pLongi);
	printf("Valor de pFloar\t: %f\n",*pFloat);
	printf("Valor de pDouble: %f\n",*pDouble);
	printf("Valor de pVoid\t: %i\n",*(int *)pVoid);
	
	*pInt = 167;
	*pChar = *pChar + 32;
	*pLongi = 300;
	*pFloat = 93.431;
	*pDouble = 13.99; 
	
	
	printf("\nDesplegamos los valores de los punteros y variables\n");
	printf("Valor puntero pInt\t: %5i - Variable\t: %i\n",*pInt,xInt);
	printf("Valor puntero pChar\t: %5c - Variable\t: %c\n",*pChar,xChar);
	printf("Valor puntero pLongi\t: %5li - Variable\t: %li\n",*pLongi,xLongi);
	printf("Valor puntero pFloat\t: %5.2f - Variable\t: %.2f\n",*pFloat,xFloat);
	printf("Valor puntero pDouble\t: %5.2f - Variable\t: %.2f\n",*pDouble,xDouble);
	
	printf("\nGuardamos distintos tipos de datos en otros\n");
	pInt = pChar;
	printf("Guardamos la direccion de pChar en pInt \t\t: %10c - Direccion de memoria\t: %p\n",*pInt,pInt);
	pInt = pLongi;
	printf("Guardamos la direccion de pLongi en pInt\t\t: %10i - Direccion de memoria\t: %p\n",*pInt,pInt);
	//SE GUARDA LA DIRECCION DE MEMORIA CORRECTAMENTE PERO NO SE PUEDE DESPLEGAR EL VALOR
	pInt = pFloat;
	printf("Guardamos la direccion de pFloar en pInt\t\t: %10i - Direccion de memoria\t: %p\n",*pInt,pInt);
	pInt = (int *)pFloat;// el cast cambien falla al desplegar el valor
	printf("Guardamos la direccion de pFloar con cast en pInt\t: %10i - Direccion de memoria\t: %p\n",*pInt,pInt);
	pInt = pDouble;
	printf("Guardamos la variable de pDouble en pInt\t\t: %10i - Direccion de memoria\t: %p\n",*pInt,pInt);
	pInt = (int *)pDouble;
	printf("Guardamos la direccion de pDouble con cast en pInt\t: %10i - Direccion de memoria\t: %p\n",*pInt,pInt);
	return 0;
}
