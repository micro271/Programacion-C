/*Mi propio programa para cambiar numeros a romanos*/

#include<stdio.h>
#include<string.h>

int main()
{
	int numero,unidad,decena,centena,unidad_de_mil;
	char romano[10] = "";
	do{
		printf("Digite un numero: ");
		fflush(stdin);
		scanf("%i",&numero);
	}while(numero > 3000 && numero < 0);
	
	unidad = numero%10;
	numero /= 10;
	
	decena = numero%10;
	numero /= 10;
	
	centena = numero%10;
	numero /= 10;
	
	unidad_de_mil = numero%10;
	
	switch(unidad_de_mil)
	{
		case 1:
			strcat(romano,"M");
			break;
		case 2:
			strcat(romano,"MM");
			break;
		case 3:
			strcat(romano,"MMM");
			break;
	}
	
	switch(centena)
	{
		case 1:
			strcat(romano,"C");
			break;
		case 2:
			strcat(romano,"CC");
			break;
		case 3:
			strcat(romano,"CCC");
			break;
		case 4:
			strcat(romano,"CD");
			break;
		case 5:
			strcat(romano,"D");
			break;
		case 6:
			strcat(romano,"DC");
			break;
		case 7:
			strcat(romano,"DCC");
			break;
		case 8:
			strcat(romano,"DCCC");
			break;
		case 9:
			strcat(romano,"CM");
			break;
	}
	
	switch(decena)
	{
		case 1:
			strcat(romano,"X");
			break;
		case 2:
			strcat(romano,"XX");
			break;
		case 3:
			strcat(romano,"XXX");
			break;
		case 4:
			strcat(romano,"XL");
			break;
		case 5:
			strcat(romano,"L");
			break;
		case 6:
			strcat(romano,"LX");
			break;
		case 7:
			strcat(romano,"LXX");
			break;
		case 8:
			strcat(romano,"LXXX");
			break;
		case 9:
			strcat(romano,"XC");
			break;
	}
	
	switch(unidad)
	{
		case 1:
			strcat(romano,"I");
			break;
		case 2:
			strcat(romano,"II");
			break;
		case 3:
			strcat(romano,"III");
			break;
		case 4:
			strcat(romano,"IV");
			break;
		case 5:
			strcat(romano,"V");
			break;
		case 6:
			strcat(romano,"VI");
			break;
		case 7:
			strcat(romano,"VII");
			break;
		case 8:
			strcat(romano,"VIII");
			break;
		case 9:
			strcat(romano,"IX");
			break;
	}
	
	printf("%s",romano);
	return 0;
}
