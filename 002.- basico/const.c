#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	const int num1 = 10; 
	const int num2 = 30;
	
	const int *p1_num1;	//Se puede apuntar a otros numeros pero no cambiar su valor
	p1_num1 = &num1;
	
	printf("%i\n",*p1_num1);
	int *const p2_num1 = &num1; //Se puede cambiar el valor pero no puede apuntar a otro numero
	*p2_num1 = 15;
	fprintf(stdout,"%i\n",*p2_num1);
	printf("%i\n",*p1_num1);
	
	p1_num1 = &num2;
	fprintf(stdout,"%i\n",*p1_num1);

	const int *const p3_num1 = &num1; //Esto no permite ni cambiar del valor que apunta ni de valor;
	

	system("pause");
	return 0;
}
