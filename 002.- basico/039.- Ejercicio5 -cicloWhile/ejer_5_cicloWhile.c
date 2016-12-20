//sumar 1-2+3-4+5...n intercalando signos empezando por -;

#include<stdio.h>

int main()
{
	int num,x,resp = 0;
	
	do{
		printf("Digite un numero +: ");
		fflush(stdin);
		scanf("%i",&num);
	}while(num < 0);
	
	x = 0;
	while(x <= num)
	{
		if(x%2==0) resp -= x;
		else resp += x;
		x++;
	}
	printf("%i",resp);
}
