/*Calcular la cantidad de segundos que estan incluidos en el numero de horas, minutos y segundos ingresados por el usuario*/

#include<stdio.h>

int main() {
	int hour,minutes,seconds;
	do{
		printf("ingrese la cantidad de horas: ");
		fflush(stdin);
		scanf("%i",&hour);
	}while(hour < 0 || hour > 24);
	
	do{
		printf("Ingrese los minutos: ");
		fflush(stdin);
		scanf("%i",&minutes);
	}while(minutes < 0 || minutes > 60);
	
	do{
		printf("Ingrese los segundos");
		fflush(stdin);
		scanf("%i",&seconds);
	}while(seconds > 60 || seconds < 0);
	
	int hour_a_seconds,minutes_a_seconds;
	hour_a_seconds = hour * 3600;
	minutes_a_seconds = minutes * 60;
	int total_seconds;
	total_seconds = hour_a_seconds + minutes_a_seconds + seconds;
	printf("El total de segundos es: %i",total_seconds);
	return 0;
}
