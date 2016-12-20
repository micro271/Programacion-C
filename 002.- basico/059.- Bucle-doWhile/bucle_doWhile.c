/*
	** bucle do,while
	
	sintaxyis:
				do{
					..Instrucciones
				}while(condicional)
*/

//mostrar los 10 primeros numeros
//saludo

#include<stdio.h>

int main()
{
	int i = 1;
	do{
		printf("%i\n",i);
		i++;
	}while(i <= 10);
	
	
	char opc;
	
	do{
		printf("Ohayougozaimasu\n");
		printf("Para volver a saludar presione 's': ");
		fflush(stdin);
		scanf("%c",&opc);
	}while(opc == 's' || opc == 'S');
	return 0;
}
