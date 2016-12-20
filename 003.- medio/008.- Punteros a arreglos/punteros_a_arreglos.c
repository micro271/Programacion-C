#include <stdio.h>
#include <string.h>
#include <limits.h>
int i;
int main(int argc,char **argv) {
	char arrChar[11];
	short int arrShrtI[10];
	unsigned short int arrUShrtI[10];
	int arrInt[10];
	unsigned int arrUInt[10];
	long int arrLongI[10];
	long long int arrLongLI[10];
	unsigned long long int arrULongLI[10];
	float arrFloat[10];
	double arrDouble[10];
	long double arrLondD[10];
	
	strcpy(&arrChar[0],"HOLA MUNDO");
	for(i = 0; i < 10; i++){
		arrShrtI[i] = i*i;
		arrUShrtI[i] = i*(i*2);
		arrInt[i] = (i+1)*10;
		arrUInt[i] = 40;
		arrLongI[i] = (LONG_MAX/(i+1));
		arrLongLI[i] = (LLONG_MAX/(i+1));
		arrULongLI[i] = (ULLONG_MAX/(i+1));
		arrFloat[i] = 3.1416*(i+1);
		arrDouble[i] = 2.71*(i*5);
		arrLondD[i] = 2.71*((i+1)*10);
	}
	
	
	char *arrCharP;
	short int *arrShrtIP;
	unsigned short int *arrUShrtIP;
	int *arrIntP;
	unsigned int *arrUIntP;
	long int *arrLongIP;
	long long int *arrLongLIP;
	unsigned long long int *arrULongLIP;
	float *arrFloatP;
	double *arrDoubleP;
	long double *arrLondDP;
	
	printf("Tamaño en bytes de los arrays de longitud 10\n");
	printf("Bytes de arrChar\t: %4i - Bytes individuables\t: %i\n",sizeof(arrChar),sizeof(char));
	printf("Bytes de arrShrtI\t: %4i - Bytes individuables\t: %i\n",sizeof(arrShrtI),sizeof(short int));
	printf("Bytes de arrUShrtI\t: %4i - Bytes individuables\t: %i\n",sizeof(arrUShrtI),sizeof(unsigned short int));
	printf("Bytes de arrInt \t: %4i - Bytes individuables\t: %i\n",sizeof(arrInt),sizeof(int));
	printf("Bytes de arrUInt\t: %4i - Bytes individuables\t: %i\n",sizeof(arrUInt),sizeof(unsigned int));
	printf("Bytes de arrLongI\t: %4i - Bytes individuables\t: %i\n",sizeof(arrLongI),sizeof(long int));
	printf("Bytes de arrLongLI\t: %4i - Bytes individuables\t: %i\n",sizeof(arrLongLI),sizeof(long long int));
	printf("Bytes de arrULongLI\t: %4i - Bytes individuables\t: %i\n",sizeof(arrULongLI),sizeof(unsigned long long int));
	printf("Bytes de arrFloat\t: %4i - Bytes individuables\t: %i\n",sizeof(arrFloat),sizeof(float));
	printf("Bytes de arrDouble\t: %4i - Bytes individuables\t: %i\n",sizeof(arrDouble),sizeof(double));
	printf("Bytes de arrLondD\t: %4i - Bytes individuables\t: %i\n",sizeof(arrLondD),sizeof(long double));
	
	printf("\nTamaño en bytes de los Punteros\n");
	printf("Bytes de arrCharP\t: %4i\n",sizeof(arrCharP));
	printf("Bytes de arrShrtIP\t: %4i\n",sizeof(arrShrtIP));
	printf("Bytes de arrUShrtIP\t: %4i\n",sizeof(arrUShrtIP));
	printf("Bytes de arrIntP \t: %4i\n",sizeof(arrIntP));
	printf("Bytes de arrUIntP\t: %4i\n",sizeof(arrUIntP));
	printf("Bytes de arrLongIP\t: %4i\n",sizeof(arrLongIP));
	printf("Bytes de arrLongLIP\t: %4i\n",sizeof(arrLongLIP));
	printf("Bytes de arrULongLIP\t: %4i\n",sizeof(arrULongLIP));
	printf("Bytes de arrFloatP\t: %4i\n",sizeof(arrFloatP));
	printf("Bytes de arrDoubleP\t: %4i\n",sizeof(arrDoubleP));
	printf("Bytes de arrLondDP\t: %4i\n",sizeof(arrLondDP));
	
	printf("\nDireccion de memoria de los arrays\n");
	printf("Direccion de memoria de arrChar \t: %p - %u\n",arrChar,arrChar);
	printf("Direccion de memoria de arrShrtI\t: %p - %u\n",arrShrtI,arrShrtI);
	printf("Direccion de memoria de arrUShrtI\t: %p - %u\n",arrUShrtI,arrUShrtI);
	printf("Direccion de memoria de arrInt  \t: %p - %u\n",arrInt,arrInt);
	printf("Direccion de memoria de arrUInt \t: %p - %u\n",arrUInt,arrUInt);
	printf("Direccion de memoria de arrLongI\t: %p - %u\n",arrLongI,arrLongI);
	printf("Direccion de memoria de arrLongLI\t: %p - %u\n",arrLongLI,arrLongLI);
	printf("Direccion de memoria de arrULongLI\t: %p - %u\n",arrULongLI,arrULongLI);
	printf("Direccion de memoria de arrFloat\t: %p - %u\n",arrFloat,arrFloat);
	printf("Direccion de memoria de arrDouble\t: %p - %u\n",arrDouble,arrDouble);
	printf("Direccion de memoria de arrLondD\t: %p - %u\n",arrLondD,arrLondD);
	//arrChar == &arrChar[0];
	arrCharP = arrChar;
	arrShrtIP = &arrShrtI[0];
	arrUShrtIP = arrUShrtI;
	arrIntP = arrInt;
	arrUIntP = arrUInt;
	arrLongIP = arrLongI;
	arrLongLIP = &arrLongLI[0];
	arrULongLIP = arrULongLI;
	arrFloatP = arrFloat;
	arrDoubleP = arrDouble;
	arrLondDP = arrLondD;
	
	printf("\nDesplegamos valores espcificos de las variables y punteros\n");
	/*
		TANTO LOS ARREGLOS DE DATOS CONSTANTES Y PUNTEROS SE PUEDEN ACCEDER A LOS
		VALORES UTILIZANDO EL CORCHETE Y ACCEDIENDO A SU POSICION ADEMAS DE ESTA FORMA TAMBIEN
		SE PUEDE ACCEDER CON EL OPERADOR DE INDIRECCION COLOCANDO ENTRE PARENTECIS EL NOMBRE
		DEL ARRAY SUMANDOLE LA POSICION Q SE DECEA OBTENER
			ejmp:
					array[5]	->	accedemos a la posicion 5 sea tipo de dato constante o puntero
					*(array+5)	->	Accedemos a la posicion 5 sea tipo de dato constante o puntero
	*/
	printf("Valor de la posicion 3 del puntero arrCharP\t: %c - Valor de la variable arrChar\t: %c\n",arrCharP[3],arrChar[3]);
	printf("Valor de la posicion 8 del puntero arrShrtIP\t: %hi - Valor de la variable arrShrtI\t: %hi\n",*(arrShrtIP+8),*(arrShrtI+8));
	printf("Valor de la posicion 1 del puntero arrUShrtIp\t: %hu - Valor de la variable arrUShrtI\t: %hi\n",arrUShrtIP[1],arrUShrtI[1]);
	printf("Valor de la posicion 4 del puntero arrIntP   \t: %i - Valor de la variable arrInt   \t: %i\n",arrIntP[4],arrInt[4]);
	printf("Valor de la posicion 2 del puntero arrUIntP \t: %u - Valor de la variable arrUInt\t: %u\n",arrUIntP[2],arrUInt[2]);
	printf("Valor de la posicion 6 del puntero arrLongIP\t: %li - Valor de la variable arrLongI\t: %li\n",arrLongIP[6],arrLongI[6]);
	printf("Valor de la posicion 7 del puntero arrLongLIP\t: %lli - Valor de la variable arrLongLI\t: %lli\n",*(arrLongLIP+7),*(arrLongLI+7));
	printf("Valor de la posicion 9 del puntero arrULongLIP\t: %llu - Valor de la variable arrULongLI\t: %llu\n",arrULongLIP[9],arrULongLI[9]);
	printf("Valor de la posicion 5 del puntero arrFloatP\t: %.2f - Valor de la variable arrFloat\t: %f\n",arrFloatP[5],arrFloat[5]);
	printf("Valor de la posicion 8 del puntero arrDoubleP\t: %.2f - Valor de la variable arrDouble\t: %f\n",arrDoubleP[8],arrDouble[8]);
	printf("Valor de la posicion 7 del punteto arrLondDP\t: %.2f - Valor de la variable arrLondD\t: %.2f\n",arrLondDP[7],arrLondD[7]);
	return 0;
}
