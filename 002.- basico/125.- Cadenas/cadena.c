#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char saludo[] = "Hola";
	printf("\n\t%s\n",saludo);
	printf("\n%i\n",strlen(saludo));
	char *p_saludo;
	p_saludo = &saludo[0];
	printf("\n\t%c\n",*(p_saludo+1));
	
	char *saludo2 = (char *)malloc(5*sizeof(char));
	saludo2[0] = 'H';
	saludo2[1] = 'O';
	saludo2[2] = 'L';
	saludo2[3] = 'A';
	printf("\n\tasd %c\n",*saludo2);
	system("pause");
	return 0;
}
