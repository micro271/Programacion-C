/*Visualizar la tarifa de luz segun el gasto de corriente electrica 
Para un gasto menor de 1.000kWh la tarifa es 1.2, entre 1.000 y 1.850kWh es 1.0 y mayor a 1850kWh es0.9*/

#include<stdio.h>
#define TARIFA1 1.2
#define TARIFA2 1.0
#define TARIFA3 0.9


int main() {
	float gasto,tasa;
	printf("Digite el total de gasto de energia: ");
	fflush(stdin);
	scanf("%f",&gasto);
	
	if(gasto < 1000) tasa = TARIFA1;
	else if(gasto >= 1000 && gasto <= 1850) tasa = TARIFA2;
	else if(gasto > 1850) tasa = TARIFA3;
	printf("%.1f",tasa);
	return 0;
}
