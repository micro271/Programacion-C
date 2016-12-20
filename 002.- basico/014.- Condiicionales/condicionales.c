#include<stdio.h>

int main() {
	int x,y;
	printf("Ingrese el valor de el devidendo y el devisor separados por espacios: ");
	fflush(stdin);
	scanf("%i %i",&x,&y);
	if(x%y == 0) printf("%i y %i son divisores\n",x,y);
	
	int i,err;
	if(err=scanf("%i",&i) == 0)
	{
		printf("ERRORRRRRR");
	}
	return 0;
}
