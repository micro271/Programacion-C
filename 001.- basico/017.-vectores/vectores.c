#include<stdio.h>

int main(void)
{
    printf("Bienvenido a la fabrica de vectores\n");
    size_t largo;
    
    printf("ingrese el largo de su vector: \n");
    fflush(stdin);
    scanf("%i",&largo);
    
    printf("El largo ingresado es: %i \n",largo);
    
    int vector1[largo];
    int i;
    for(i = 0; i <= largo; i++)
    {
    	printf("Ingrese el valor para la posicion: %d => ",i);
    	fflush(stdin);
    	scanf("%d",&vector1[i]);
	}
	for(i = 0; i <= largo; i++)
	{
		printf("vector1[%i] = %i\n",i,vector1[i]);
	}
    return 0;
}
