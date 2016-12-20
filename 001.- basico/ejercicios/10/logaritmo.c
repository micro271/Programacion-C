/*Determinar un logaritmo*/
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


void sacar_log(int *base, int *argumento,int *exponente);

int main() {
	int base,argumento,exponente;
	sacar_log(&base,&argumento,&exponente);
	
	printf("%i",exponente);
	return 0;
}

void sacar_log(int *base, int *argumento,int *exponente) {
	printf("Ingrese la base del logaritmo: ");
	fflush(stdin);
	scanf("%i",base);
	
	printf("Ingresa el argumento del logaritmo: ");
	fflush(stdin);
	scanf("%i",argumento);
	
	int i = 0;
	int resp = 0;
	while(*argumento != resp)
	{
		resp = pow(*base,i);
		if(*argumento == resp)
		{
			*exponente = i;
		}
		else
		{
			if(i > 1000)
			{
				printf("\nNo tiene una solucion entera\n");
				break;
			}
			else
			{	
				i++;
			}
		}
	}
}








