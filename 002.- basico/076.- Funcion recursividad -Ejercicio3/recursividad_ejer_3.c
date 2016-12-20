//Pasar un numero n a binario

#include<stdio.h>
void binario(int n);
int main()
{
	int n;
	do{
		printf("Digite un numero: ");
		fflush(stdin);
		scanf("%i",&n);
	}while(n < 0);
	
	binario(n);
	
	return 0;
}

void binario(int n)
{
	if(n > 1)
	{
		binario(n/2);
	}
	
	printf("%i",n%2);
	
}
