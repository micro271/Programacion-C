#include <stdio.h>
#include <string.h>

void cambiar(int *val1,int *val2);
void charac(char *letra,char caracter);
int suma(int *x, int *y);

int main() {
	int a=0; //Declaración de variable entera de tipo entero
	int *puntero; //Declaración de variable puntero de tipo entero
	puntero = &a; //Asignación de la dirección memoria de a
	//con *puntero obtenemos el valor que se encuentra en esa direccion de memoria
	//con solo puntero accedemos a la direccion
	printf("El valor de a es: %d. \nEl valor de *puntero es: %d. \n",a,*puntero);
	printf("La direccion de memoria de *puntero es: %p\n",puntero);
	
	
	// con numeros
	int x = 4, b = 7;
	printf("\nx: %d b: %d\n",x,b);
	cambiar(&x,&b);
	printf("x: %d, b: %d\n",x,b);
	
	//con character
	char i = 'z';
	char e = 'j';
	printf("\na -> %c, e -> %c\n",i,e);
	charac(&i,'h');
	charac(&e,'m');
	printf("a -> %c, e -> %c\n",i,e);
	
	//suma
	int num1 = 9;
	int num2 = 8;
	printf("\nSumamos x e y: %d",suma(&num1,&num2));
	return 0;
}

void cambiar(int *val1,int *val2) {
	int z;
	z = *val1;
	*val1 = *val2;
	*val2 = z;
}

void charac(char *letra, char caracter) {
	*letra = caracter;
}

int suma(int *x, int *y) {
	return *x + *y;
}
