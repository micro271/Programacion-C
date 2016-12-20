//Calcula el nuevo salario de un obrero si obtubo un incremento del 25% sobre su salario anterior

#include <stdio.h>

int main() {
	float salario_anterior,comision,salario_final;
	
	printf("Cual fue su salario anterior?: ");
	fflush(stdin);
	scanf("%f",&salario_anterior);
	
	printf("Cuanto es el incremento del salario con respecto al del anterior mes?: ");
	fflush(stdin);
	scanf("%f",&comision);
	
	float desc;
	desc = (comision * salario_anterior)/100;
	salario_final = salario_anterior + desc;
	printf("El salario de este mes con el incremento de %.1f es de: %.1f",comision,salario_final);
	
	return 0;
}
