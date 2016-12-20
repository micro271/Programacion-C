#include<stdio.h>


int main()
{
	char vector_de_caracteres[] = "Estoy aprendiendo a programar en C";
	printf("%s\n",vector_de_caracteres);
	
	char * saludo = "Hola mundo";
	printf("%s\n",saludo);
	
	char * al_vector = NULL;
		al_vector = &vector_de_caracteres[0];
//	OR	al_vector = vector_de_caracteres;

	printf("%s\n",al_vector);
	
	printf("%c",al_vector[0]);
	return 0;
}
