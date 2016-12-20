/*Hacer un programa que simule un cajero automatico con un saldo inicial de 1000 dolares*/

#include<stdio.h>

int main() 
{
	int opcion;
	float saldo = 1000;
	float agregar;
	float retirar;
	
	printf("\tBienvenido a su cajero virtual");
	printf("\n1. Ingreso en cuenta");
	printf("\n2. Retirar dinero de la cuenat");
	printf("\n3. Salir");
	do{
		printf("\nDigite su opcion: ");
		fflush(stdin);
		scanf("%i",&opcion);
	}while(opcion < 0 && opcion > 3);
	
	
	switch(opcion)
	{
		case 1:
			do{
				printf("Cuanto dinero decea ingresar en la cuenta: ");
				fflush(stdin);
				scanf("%f",&agregar);
			}while (agregar < 0);
			saldo += agregar;
			printf("El saldo total es de: %.2f",saldo);
			break;
		case 2:
			printf("Cuanto dinero decea retirar: ");
			fflush(stdin);
			scanf("%f",&retirar);
			if(retirar > saldo) printf("La cantidad que decea retirar es mayor al saldo\n");
			do{
				printf("Cuanto dinero decea retirar: ");
				fflush(stdin);
				scanf("%f",&retirar);
			}while(retirar > saldo && retirar < 0);
			saldo -= retirar;
			printf("El saldo disponible es de: %.2f",saldo);
			break;
		case 3:
			break;		
	};
	return 0;	
}









