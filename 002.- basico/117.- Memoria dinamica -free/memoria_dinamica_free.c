//free(puntero)

#include<stdio.h>
#include<stdlib.h>


int main()
{
	int *p1;
	
	p1 = (int * )malloc(sizeof(int));
	if(p1 == NULL)
	{
		fprintf(stdout,"Memoria llena\n");
	}
	else
	{
		fprintf(stdout,"Hay espacio\n");
		*p1 = 15;
		fprintf(stdout,"%i\n",*p1);
	}
	
	free(p1);
	fprintf(stdout,"%i\n",*p1);
	
	system("pause");
	return 0;
}
