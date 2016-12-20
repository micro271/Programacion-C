#include <stdio.h>

int main(void)
{
	int i,cantidad;
	i = 0;
	cantidad = 3000;
	while(i <= cantidad)
	{
		if(i%3==0) printf("Multiplo de 3: %i\n",i);
		i++;
	}
	return 0;
}
