/*
		0 = false		verdadero = x > 0, v'x'e n;
	
	int isalnum(int c)	->Comprueba su el caracter es alfanumerico
		!= 0 - es alfanumerico;
		== 0 - no es alfanumerico
		
	int isalpha(int c)	->Comprueba si el entero contiene una letra del alfabeto
		!= 0 - es alfabetico;
		== 0 - no es alfabetico
		
	int isdigit(inr c)	->Comprueba si el entero es un digito;
		!= 0 - si es digito
		== 0 - no es digito
		
	int isgraph(inr c)	->Comprueba si un caracter puede verse graficamente;
		!= 0 - si se puede ver
		== 0 - no se puede ver
		
	int islower(inr c)	->Comprueba si el entero es un caracter en minusculas;
		!= 0 - si es minusculas
		== 0 - no es minusculas
		
	int isprint(inr c)	->Comprueba si el entero es un caracter imprimible;
		!= 0 - si se puede imprimir
		== 0 - no se puede imprimir
		
	int isspace(int c)	->Comprueba si el caracter es un espacio
		!= 0 - si es un espacio;
		== 0 - no es un espacio
		
	int ispunct(int c)	->Comprueba si es un caracter de puntuacion;
		!= 0 - si es un caracter de puntuacion
		== 0 - no es un caracter de puntuacion
		
	int isxdigit(int c)	->Comprueba si es un caracte hexadecimal;
		!= 0 - es un caracter hexadecimal;
		== 0 - no es un caracter hexadecimal
		
	int isupper(int c)	->Comprueba que un caracter este en mayusculas;
		!= 0 - el caracter esta en mayusculas;
		== 0 - el caracter esta en minusculas;
*/

#include<stdio.h>
#include<ctype.h>
int i;

int alphanumerico(const int);
int alphabetic(const int);
int main()
{
	int (*isal[2])(const int);
	isal[0] = alphanumerico;
	isal[1] = alphabetic;
	
	int n[7];
		n[0] = 's';
		n[1] = '\t';
		n[2] = '.';
		n[3] = '1';
		n[4] = ' ';
		n[5] = '9';
		n[6] = 'M';
		fprintf(stdout,"\t\t** 0 == VERDADERO & != 0 FALSO");
	/*			int isalnum(int *)			*/
	fprintf(stdout,"\n\t\t**Funcion int isalnum(int c)**\n\n");
	for(i = 0; i < 7; i++)
	{
		if(isal[0](n[i]) != 0)
		{
			fprintf(stdout,"isalnum(%c) = %i\t-> |Es! un caracter alfanumerico|\n",n[i],isal[0](n[i]));
		}
		else
		{
			fprintf(stdout,"isalnum(%c) = %i\t-> |No! es un caracter alfanumerico|\n",n[i],isal[0](n[i]));
		}
	}
	fprintf(stdout,"\n");

	
	/*			int isalpha(const int c)			*/
	fprintf(stdout,"\n\n\t\t**Funcion int isalpha(int c)**\n");
	for(i = 0; i < 7; i++)
	{
		if(isal[1](n[i]) != 0)
		{
			fprintf(stdout,"isalpha(%c) = %i\t-> |Es! un caracter alfabetico|\n",n[i],isal[1](n[i]));
		}
		else
		{
			fprintf(stdout,"isalpha(%c) = %i\t-> |No! es un caracter alfabetico|\n",n[i],isal[1](n[i]));
		}
	}
	
	/*			int isdigit(int c)			*/
	fprintf(stdout,"\n\n\t\t**Funcion int isdigit(int c)**\n");
	for(i = 0; i < 7; i++)
	{
		if(isdigit(n[i]) != 0)
		{
			fprintf(stdout,"isdigit(%c) = %i\t-> |Es! un DIGITO|\n",n[i],isdigit(n[i]));
		}
		else
		{
			fprintf(stdout,"isdigit(%c) = %i\t-> |No! es un DIGITO|\n",n[i],isdigit(n[i]));
		}
	}
	
	/*			int isgraph(int c)			*/
	fprintf(stdout,"\n\n\t\t**Funcion int isgraph(int c)**\n");
	
	for(i = 0; i < 7; i++)
	{
		if(isgraph(n[i]) != 0)
		{
			fprintf(stdout,"isgraph(%c) = %i\t-> |Es! un caracter VISUAL|\n",n[i],isgraph(n[i]));
		}
		else
		{
			fprintf(stdout,"isgraph(%c) = %i\t-> |No! es un caracter VISUAL|\n",n[i],isgraph(n[i]));
		}
	}
	
	/*			int islower(int c)			*/
	int m[5];
		m[0] = 'a';
		m[1] = '2';
		m[2] = 'A';
		m[3] = 'n';
		m[4] = 'M';
	fprintf(stdout,"\n\n\t\t**Funcion int islower(int c)**\n");
	
	for(i = 0; i < 5; i++)
	{
		if(islower(m[i]) != 0)
		{
			fprintf(stdout,"islower(%c) = %i\t-> |Es! un caracter en MINUSCULAS|\n",m[i],islower(m[i]));
		}
		else
		{
			fprintf(stdout,"isdigit(%c) = %i\t-> |No! es un caracter en MINUSCULAS|\n",m[i],isdigit(m[i]));
		}
	}
	
	/*			int isprint(int c)			*/

	fprintf(stdout,"\n\n\t\t**Funcion int isprint(int c)**\n");
	for(i = 0; i < 7; i++)
	{
		if(isprint(n[i]) != 0)
		{
			fprintf(stdout,"isprint(%c) = %i\t-> |Es! caracter REPRECENTATIVO|\n",n[i],isprint(n[i]));
		}
		else
		{
			fprintf(stdout,"isprint(%c) = %i\t-> |No! es un caracter REPRECENTATIVO|\n",n[i],isprint(n[i]));
		}
	}
	
	
	/*			int isspace(int c)			*/
	int s[5];
		s[0] = '\t';
		s[1] = '\v';
		s[2] = ' ';
		s[3] = '\f';
		s[4] = '\r';
	fprintf(stdout,"\n\n\t\t**Funcion int isspace(int c)**\n");
	for(i = 0; i < 5; i++)
	{
		if(isspace(s[i]) != 0)
		{
			fprintf(stdout,"isspace(%c) = %i\t-> |Es! caracter de ESPACIADO|\n",s[i],isspace(s[i]));
		}
		else
		{
			fprintf(stdout,"isspace(%c) = %i\t-> |No! es un caracter de ESPACIADO|\n",s[i],isspace(s[i]));
		}
	}
	
	/*			int isupper(int c)			*/
	fprintf(stdout,"\n\n\t\t**Funcion int isupper(int c)**\n");
	for(i = 0; i < 5; i++)
	{
		if(isupper(m[i]) != 0)
		{
			fprintf(stdout,"isupper(%c) = %i\t-> |Es! caracter en MAYUSCULAS|\n",m[i],isupper(m[i]));
		}
		else
		{
			fprintf(stdout,"isupper(%c) = %i\t-> |No! es un caracter en MAYUSCULAS|\n",m[i],isupper(m[i]));
		}
	}
	
	
	/*			int ispunct(int c)			*/
	fprintf(stdout,"\n\n\t\t**Funcion int ispunct(int c)**\n");
	for(i = 0; i < 7; i++)
	{
		if(ispunct(n[i]) != 0)
		{
			fprintf(stdout,"ispunct(%c) = %i\t-> |Es! caracter de PUNTUACION|\n",n[i],ispunct(n[i]));
		}
		else
		{
			fprintf(stdout,"ispunct(%c) = %i\t-> |No! es un caracter de PUNTUACION|\n",n[i],ispunct(n[i]));
		}
	}
	

	system("pause");
	return 0;
}

int alphanumerico(const int x)
{
	return isalnum(x);
}

int alphabetic(const int x)
{
	return isalpha(x);
}
