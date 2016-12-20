/*
	**Vectores/arrays Bidimencionales;
		Son aquellos que tienen un determinado numero de fijas y columnas, empieza desde 0 hasts numeros de filas
		y columnas a esto se le denomina matriz o tabla;
		
		filas = 0..n;
		columnas = 0..m;
		
		TipoDeDato Nombre[numeroColumnas][numeroFilas];
*/

#include<stdio.h>

int main()
{
	size_t numeroDeColumnas = 2;
	size_t numeroDeFilas = 5;
	int tabla[2][5] = {{6,1,2,49,1},{12,1,3,213,12}};
	int filas = 0,columnas = 0;;
	while(filas < 5)
	{
		if(columnas == 0)
		{
			printf("%i, ",tabla[columnas][filas]);
			filas++;
			if(filas == 5)
			{
				filas = 0;
				columnas++;
				printf("\n");
			}
		}
		else if(columnas==1)
		{
			printf("%i, ",tabla[columnas][filas]);
			filas++;
		}
	}
	
	
	
	return 0;
}
