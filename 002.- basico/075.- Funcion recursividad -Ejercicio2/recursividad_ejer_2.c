/*Consideremos una funcion que recibe un numero n e imprima los numeros del n al a con recursividad*/

#include<stdio.h>

int descendente(int n);
int main()
{
	int n;
	printf("Digite hasta donde quiere llegar: ");
	fflush(stdin);
	scanf("%i",&n);
	
	int i;
	for(i = n; i >= 1; i--)
	{
		printf("%i, ",descendente(i));
	}

	return 0;
}

int descendente(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else
	{
		return descendente(n - 1) + 1;
	}

}

*/
