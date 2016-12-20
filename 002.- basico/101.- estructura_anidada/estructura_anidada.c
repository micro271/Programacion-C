//Estructuras anidadas

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char direccion[50];
	char ciudad[20];
	char provincia[20];	
}info_d;

typedef struct
{
	char nombre[30];
	info_d dir_empleado;
	long long salario;
}empleado;

int main(void)
{
	int i,n;
	empleado e[2];
	for(i = 0; i < 2; i++)
	{
		printf("%i. Digite su nombre: ",i+1);
		fflush(stdin);
		gets(e[i].nombre);
		for(n = 0; n <= strlen(e[i].nombre); n++)
		{
			if(i == strlen(e[i].nombre))
			{
				e[i].nombre[n] = '\0';
				continue;
			}
			if(n == 0 && e[i].nombre[0] != ' ')
			{
				e[i].nombre[n] = toupper(e[i].nombre[n]);
			}
			if(e[i].nombre[n] == ' ')
			{
				e[i].nombre[n+1] = toupper(e[i].nombre[n+1]);
			}
		}
		printf("%i. Digite su direccion: ",i+1);
		fflush(stdin);
		gets(e[i].dir_empleado.direccion);
		for(n = 0; n < strlen(e[i].dir_empleado.direccion); n++)
		{
			if(n == strlen(e[i].dir_empleado.direccion))
			{
				e[i].dir_empleado.direccion[n] = '\0';
				continue;
			}
			
			if(n == 0 && e[i].dir_empleado.direccion[0] != ' ')
			{
				e[i].dir_empleado.direccion[n] = toupper(e[i].dir_empleado.direccion[n]);
			}
			if(e[i].dir_empleado.direccion[n] == ' ')
			{
				e[i].dir_empleado.direccion[n+1] = toupper(e[i].dir_empleado.direccion[n+1]);
			}
		}
		
		printf("%i. Digite su ciudad: ",i+1);
		fflush(stdin);
		gets(e[i].dir_empleado.ciudad);
		
		for(n = 0; n <= strlen(e[i].dir_empleado.ciudad); n++)
		{
			if(n == strlen(e[i].dir_empleado.ciudad))
			{
				e[i].dir_empleado.ciudad[n] = '\0';
				continue;
			}
			if(n == 0 && e[i].dir_empleado.ciudad[0] != ' ')
			{
				e[i].dir_empleado.ciudad[n] = toupper(e[i].dir_empleado.ciudad[n]);
			}
			if(e[i].dir_empleado.ciudad[n] == ' ')
			{
				e[i].dir_empleado.ciudad[n+1] = toupper(e[i].dir_empleado.ciudad[n+1]);
			}
		}
		
		
		printf("%i. Digite su provincia: ",i+1);
		fflush(stdin);
		gets(e[i].dir_empleado.provincia);
		for(n = 0; n <= strlen(e[i].dir_empleado.provincia); n++)
		{
			if(i == strlen(e[i].dir_empleado.provincia))
			{
				e[i].dir_empleado.provincia[n] = '\0';
				continue;
			}
			if(n == 0 && e[i].dir_empleado.provincia[0] != ' ')
			{
				e[i].dir_empleado.provincia[n] = toupper(e[i].dir_empleado.provincia[n]);
			}
			if(e[i].dir_empleado.provincia[n] == ' ')
			{
				e[i].dir_empleado.provincia[n+1] = toupper(e[i].dir_empleado.provincia[n+1]);
			}
		}
		
		printf("%i. Digite su salario: ",i+1);
		scanf("%lli",&e[i].salario);
	}
	
	for(i = 0; i < 2; i++)
	{
		printf("\n\tEmpleado n.%i\n",i+1);
		printf("Nombre: %s\n",e[i].nombre);
		
		printf("Direccion: %s\n",e[i].dir_empleado.direccion);
		printf("Ciudad: %s\n",e[i].dir_empleado.ciudad);
		printf("Provincia: %s\n",e[i].dir_empleado.provincia);
		printf("Salario: %lli\n",e[i].salario);
	}
	system("pause");
	return 0;
}
