/*
	**Funciones:
	- Funciones sin retorno de valor:
		void nombreFuncion(parametros)
		{
			..instrucciones
		}
		
	- Funciones con retorno de valor
		tipo_dato nombreFuncion(parametro)
		{
			..Instrucciones
		}
*/

//1. Saludar por pantalla con funcion void
//2. Sumar 2 numeros

#include<stdio.h>
void saludo(void);
int suma(int x, int y);
int resta(int x, int y);
void operacion(int (*op) (int,int ) ,int x, int y);
int n_primos(int x);
int main(void)
{
	saludo();
	
	int x,y;
	printf("\nDigite los 2 numeros que deceas sumar separados por espacio: ");
	fflush(stdin);
	scanf("%i %i",&x,&y);
	int (*arit[2]) (int,int) = {suma,resta};

	operacion(arit[0],x,y);
	operacion(arit[1],x,y);
	
	int i;
	int (*p_n_primos) (int);
	p_n_primos = n_primos;
	for(i = 0; i <= 10; i++)
	{
		if(p_n_primos(i) == 0)
		{
			printf("%i, ",i);
		}
	}
	return 0;
}

int n_primos(int x)
{
	int c = 0,i;
	for(i = x; i > 0; i--)
	{
		if(x%i == 0)
		{
			c++;
		}
	}
	if(c == 2)
	{
		return 0;
	}
	else return 1;
}
void operacion(int (*op) (int,int) ,int x, int y)
{
	printf("El resultado de la operacion = %i\n",op(x,y));
}
void saludo(void)
{
	printf("Ohayougozaimasu!!!!");
}

int suma(int x, int y)
{
	return x + y;
}

int resta(int x, int y)
{
	return x - y;
}

