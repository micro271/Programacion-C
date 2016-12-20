//Sumar pares desde n hasta m

#include<stdio.h>

int main()
{
	int primer,segundo,x,resp = 0;
	
	printf("Ingrese desde que numero quiere empezar: ");
	fflush(stdin);
	scanf("%i",&primer);
	
	printf("Ingresde hasta donde quiere llegar: ");
	fflush(stdin);
	scanf("%i",&segundo);
	if(primer > segundo) printf("El segundo valor debe ser mas grande que el primero\n");
	while(primer > segundo)
	{
		printf("Ingrese el segundo valor nuevamente: ");
		fflush(stdin);
		scanf("%i",&segundo);
	}
	
	while(primer <= segundo)
	{
		if(primer%2==0) resp += primer;
		primer++;
	}
	printf("%i",resp);

	
	return 0;
}
