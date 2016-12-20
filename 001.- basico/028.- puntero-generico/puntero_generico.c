#include<stdio.h>

int main()
{
	int x = 9;
	int * puntero_entero = NULL;
	puntero_entero = &x;
	
	*puntero_entero += 2;
	printf("x\t->\t%i\n",x);
	
	/*
		** Muchas veces no se a que estoy apuntando, sea un entero, un caracter, un string asi que para
		evitar problemas usamos el 'void'
	*/
	
	x = 9;
	void * puntero_generico = NULL;
	puntero_generico = &x;
	//Convertir el puntero generico a un puntero int
	*(int *) puntero_generico -= 3;
	printf("x\t->\t%i",x);
	return 0;
}
