/*
	**realloc. Esta función también es para asignar un bloque de memoria libre. 
	Tiene una variación respecto a malloc y calloc , permite ampliar un bloque de memoria reservado 
	anteriormente. La forma de llamar a la función realloc es: 
		puntero = realloc 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	int *vector,i;
	vector = (int *)malloc(10 * sizeof(int));//reservando memoria para 10 elemenros 
	if(vector == NULL)
	{
		fprintf(stdout,"Error a asignar la memoria \n");
	}
	else
	{
		fprintf(stdout,"Exito al asignar la memoria\n");
	}
	
	for(i = 0; i < 10 ; i++)
	{
		vector[i] = 1 + rand() % ((10 + 1) - 1);
		fprintf(stdout,"%i) %i\n",1+i,vector[i]); 
	}
	
	//realloc()
	int *vector_convertido;
	vector_convertido = realloc(vector,15*sizeof(int));
	//agregando nuevos valores;
	fprintf(stdout,"\n\tAplicamos realloc() y agrandamos el vector de 10 a 15 elementos y los agregamos\n");
	for(i = 0; i < 15; i++)
	{
		if(i >= 10)
		{
			vector_convertido[i] = 1 + rand() % ((10 + 1) - 1);
		}
		fprintf(stdout,"%i) %i\n",1+i,vector_convertido[i]);
	}
	free(vector_convertido);
	system("pause");
	return 0;
}
