/*
	Reservar memoria con malloc para un array de tipo double para 1000 números, y comprobar si el puntero es válido
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int i;
	srand(time(NULL));
	double * p = (double *)malloc(sizeof(double)*5);
	if(p == NULL)
	{
		fprintf(stdout,"La memoria esta llena\n");
		return -1; //intentar recuperar memoria
	}
	else
	{
		fprintf(stdout,"Si se pudo guardar la variable\n");
		for(i = 0; i < 5; i++)
		{
			p[i] = 1 + rand() % ((5 + 1) - 1);
			fprintf(stdout,"%.2lf\n",p[i]);
		}
	}
	double p2[10] = {10.345,4.653,12.8453,4.8534,5.865,12.435,321.435,213.123,1.21,21.312};
	double * p2_p;
	p2_p = p2;
	p2_p += 6;
	printf("-> %.2lf\n",*p2_p);
	system("pause");
	return 0;
}

