#include<stdio.h>

typedef struct fecha{
	int dia;
	int mes;
	int anio;
}fecha;


fecha *crear_fecha()
{
	fecha *nueva_fecha = malloc(sizeof(fecha));
	if(nueva_fecha == NULL) printf("error");
	
	do
	{
		printf("Ingrese el dia: ");
		fflush(stdin);
		scanf("%i",&nueva_fecha->dia);
	}while(nueva_fecha->dia < 1 || nueva_fecha->dia > 31);
	do
	{
		printf("Ingrese el mes: ");
		fflush(stdin);
		scanf("%i",&nueva_fecha->mes);
	}while(nueva_fecha->mes < 1 || nueva_fecha->mes > 31);
	
	do
	{
		printf("Ingrese el año: ");
		fflush(stdin);
		scanf("%i",&nueva_fecha->anio);
	}while(nueva_fecha->anio < 1800 || nueva_fecha->anio > 2020);
	
	return nueva_fecha;
}
void imprimir_fecha(fecha *f1);
int main()
{
	fecha * f1;
	f1 = crear_fecha();
	imprimir_fecha(f1);
	
	return 0;
}

void imprimir_fecha(fecha *f1)
{
	printf("Dia: %i\n",f1->dia);
	printf("Mes: %i\n",f1->mes);
	printf("Anio: %i\n",f1->anio);
}
