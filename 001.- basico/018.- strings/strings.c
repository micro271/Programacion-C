#include<stdio.h>

int main(void)
{
	char saludo[12];
		 saludo[0] = 'H';
		 saludo[1] = 'o';
		 saludo[2] = 'l';
		 saludo[3] = 'a';
		 saludo[4] = ' ';
		 saludo[5] = 'M';
		 saludo[6] = 'u';
		 saludo[7] = 'n';
		 saludo[8] = 'd';
		 saludo[9] = 'o';
		 saludo[10]= '\o';
		 saludo[11]= '\n';
	printf("%s",saludo);	
	
	char nombre[] = "Hola Mundo!!!";
	printf("%s",nombre);
	
	return 0;
}
