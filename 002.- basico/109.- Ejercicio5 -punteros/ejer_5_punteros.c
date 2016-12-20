/*
	Dado un vector de 10 elementos = {1, 2, 3, 4, 4, 7, 8, 9, 5, 4}, escribir un programa en C 
	(haciendo uso de puntero) que muestre las direcciones de memoria de cada elemento del vector
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int vec[10] = {1, 2, 3, 4, 4, 7, 8, 9, 5, 4};
	
	int * p_vec = &vec[0];
	int i;
	for(i = 0; i < 10; i++)
	{
		printf("\nPosicion de memoria del n.%i\t-> %p\n",*p_vec,p_vec);
		p_vec++;
	}
	system("pause");
	return 0;
}
