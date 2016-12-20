/*Dadas las horas trabajadas y el valor por hora calcule su salario e imprimalo*/
#include<stdio.h>

int main() {
	float horas,precio_hora,salario;
	
	printf("Ingrese las horas trabajadas");
	fflush(stdin);
	scanf("%f",&horas);
	if(horas < 0) {
		printf("Horas negativas");
		while(horas < 0) {
			printf("\nIngrese las horas trabajadas");
			fflush(stdin);
			scanf("&f",horas);
		}
	}
	
	printf("Ingrese la ganancia por hora: ");
	fflush(stdin);
	scanf("%f",&precio_hora);
	
	salario = (horas * precio_hora);
	printf("El salario es de: %.1f",salario);
	return 0;
}
