//fecha de nacimiento


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int dos_cifras(char * fecha);
int elegir_mes(int num);
int numero_de_siglo(int fecha);
int numero_mes(int mes);
int obtenemos_el_dia(int dia_final);

int main() {
	char anio[10];
	char mes[10] = "";
	int anio_cifra;
	int mes_cifra;
	
	//Obtenemos el año
	do{
		printf("Ingresa un anio: ");
		fflush(stdin);
		gets(anio);
		anio_cifra = atoi(anio);
	}while(anio_cifra < 0 || anio_cifra > 2500);
	
	//Obtenemos el numero del mes
	do{
		printf("Ingrese el numero del mes: ");
		fflush(stdin);
		scanf("%i",&mes_cifra);
	}while(mes_cifra < 0 || mes_cifra > 12);
	
	//Obtenemos el mes
	strcpy(mes,elegir_mes(mes_cifra));

	//Obtenemos el dia
	int dia;
	do{
		printf("Digite el dia: ");
		fflush(stdin);
		scanf("%i",&dia);
	}while(dia <0 || dia > 31);

	
	//obtenemos el dia
	int resp;
	resp = (dia + numero_mes(mes_cifra)) + dos_cifras(anio) + (dos_cifras(anio)/4) + numero_de_siglo(anio_cifra);
	if(resp > 7){
		do{
			resp %= 7;
		}while(resp > 7);
	}
	printf("%s\n",obtenemos_el_dia(resp));
	
	system("pause");
	return 0;
}

int obtenemos_el_dia(int dia_final) {
	char dia[20] = "EL DIAAA";
	if(dia_final == 0) strcpy(dia,"Domingo");
	else if(dia_final == 1) strcpy(dia,"Lunes");
	else if(dia_final == 2) strcpy(dia,"Martes");
	else if(dia_final == 3) strcpy(dia,"Miercoles");
	else if(dia_final == 4) strcpy(dia,"Jueves");
	else if(dia_final == 5) strcpy(dia,"Viernes");
	else if(dia_final == 6) strcpy(dia,"Sabado");
	return dia;
}

int dos_cifras(char * fecha) {
	char el[2] = "";
	int i,j = 0;
	for(i = strlen(fecha)-2; i <= strlen(fecha); i++) {
		el[j] = fecha[i];
		j++;
	}
	int anio_cifra;
	anio_cifra = atoi(el);
	return anio_cifra;
}

int elegir_mes(int num){
	char mes[20] = "EL MES DEL AÑOO";
	switch(num) {
		case 1:
			strcpy(mes,"Enero");
			break;
		case 2:
			strcpy(mes,"Febrero");
			break;
		case 3:
			strcpy(mes,"Marzo");
			break;
		case 4:
			strcpy(mes,"Abril");
			break;
		case 5:
			strcpy(mes,"Mayo");
			break;
		case 6:
			strcpy(mes,"Junio");
			break;
		case 7:
			strcpy(mes,"Julio");
			break;
		case 8:
			strcpy(mes,"Agosto");
			break;
		case 9:
			strcpy(mes,"Septiembre");
			break;
		case 10:
			strcpy(mes,"Octubre");
			break;
		case 11:
			strcpy(mes,"Noviembre");
			break;
		case 12:
			strcpy(mes,"Diciembre");
			break;
	};
	return mes;
}

int numero_de_siglo(int fecha) {
	if(fecha >= 2400 && fecha <= 2499) {
		return 6;
	}
	else if(fecha >= 2300 && fecha <= 2399) {
		return 0;
	}
	else if(fecha >= 2200 && fecha <= 2299) {
		return 2;
	}
	else if(fecha >= 2100 && fecha <= 2199) {
		return 4;
	}
	else if(fecha >= 2000 &&  fecha <= 2099) {
		return 6;
	}
	else if(fecha >= 1900 && fecha <= 1999) {
		return 0;
	}
	else if(fecha >= 1800 && fecha <= 1899) {
		return 2;
	}
	else if(fecha >= 1700 && fecha <= 1799) {
		return 4;
	}
	else if(fecha >= 1600 && fecha <= 1699) {
		return 6;
	}
	else if(fecha >= 1400 && fecha <= 1499) {
		return 4;
	}
	else if(fecha >= 1300 && fecha <= 1399) {
		return 5;
	}
	else if(fecha >= 1200 && fecha <= 1299) {
		return 6;
	}
	else if(fecha >= 1100 && fecha <= 1199) {
		return 0;
	}
	else if(fecha >= 1000 && fecha <= 1099) {
		return 1;
	}
	else if(fecha >= 900 && fecha <= 999) {
		return 2;
	}
	else if(fecha >= 800 && fecha <= 899) {
		return 3;
	}
	else if(fecha >= 700 && fecha <= 799) {
		return 4;
	}
	else if(fecha >= 600 && fecha <= 699) {
		return 5;
	}
	else if(fecha >= 500 && fecha <= 599) {
		return 6;
	}
	else if(fecha >= 400 && fecha <= 499) {
		return 0;
	}
	else if(fecha >= 300 && fecha <= 399) {
		return 1;
	}
	else if(fecha >= 200 && fecha <= 200) {
		return 2;
	}
	else if(fecha >= 100 && fecha <= 100) {
		return 3;
	}
	else if(fecha >= 0 && fecha <= 100) {
		return 4;
	}
	
}

int numero_mes(int mes) {
	if(mes == 1) return 0;
	else if(mes == 2) return 3;
	else if(mes == 3) return 3;
	else if(mes == 4) return 6;
	else if(mes == 5) return 1;
	else if(mes == 6) return 5;
	else if(mes == 7) return 6;
	else if(mes == 8) return 2;
	else if(mes == 9) return 5;
	else if(mes == 10) return 0;
	else if(mes == 11) return 4;
	else if(mes == 12) return 5;
}
