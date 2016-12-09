/*
	Hacer un programa que almacene un vector el numero de dia que tiene cada mes (enero=31,febrero=28,marzo=3,
	abril=30,etc.), pedir al usuario el numero de mes y regresar al usuario el numero de dias de ese mes.
*/
#include <stdio.h>

int main(int argc,char **argv) {
	short int nMes[12],dia,mes,resp,opc = 1,i;
	enum {
		ENERO,
		FEBRERO,
		MARZO,
		ABRIL,
		MAYO,
		JUNIO,
		JULIO,
		AGOSTO,
		SEPTIEMBRE,
		OCTUBRE,
		NOVIEMBRE,
		DICIEMBRE
	};
	nMes[ENERO] = 31;
	nMes[FEBRERO] = 28;
	nMes[MARZO] = 31;
	nMes[ABRIL] = 30;
	nMes[MAYO] = 31;
	nMes[JUNIO] = 30;
	nMes[JULIO] = 31;
	nMes[AGOSTO] = 31;
	nMes[SEPTIEMBRE] = 30;
	nMes[OCTUBRE] = 31;
	nMes[NOVIEMBRE] = 30;
	nMes[DICIEMBRE] = 31;
	
	while(opc) {
		printf("Dias transcurridos del 2016 hasta el dia asignado\n");
		printf("Numero de dia:");fflush(stdin);scanf("%hi",&dia);
		printf("Mes: ");fflush(stdin);scanf("%hi",&mes);
		if( (mes > 0 && mes <= 12) && (dia > 0 && nMes[mes-1] >= dia) ) {
			opc = 0;
		} else {
			system("cls");
			printf("El dia o el mes ingresado no tienen coherencia\n");
		}
	}
	resp = dia;
	for(i = ENERO; i < mes-1; i++) {
		resp += nMes[i];
	}
	printf("Dias transcurridos del año: %hi\n",resp);
	return 0;
}

