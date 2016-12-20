/*
	**Libreria math.h

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void atirmetica();
void trigonometria();
int main(void)
{

	int que_hacer;
	do
	{
		if(que_hacer != NULL && (que_hacer < 1 || que_hacer > 3))
		{
			fprintf(stdout,"No existe esa opcion, digite nuevamente una opcion: ");
		}
		else
		{
			fprintf(stdout,"1) Aritmetica\n");
			fprintf(stdout,"2) Trigonometria\n");
			fprintf(stdout,"3) Algebra\n");
			fprintf(stdout,"Que decea hacer: ");
		}
		fflush(stdin);
		fscanf(stdin,"%i",&que_hacer);
	}while(que_hacer < 1 || que_hacer > 3);
	
	switch(que_hacer)
	{
		case 1: aritmetica();break;
		case 2: trigonometria();break;
	}
	system("pause");
	return 0;
}

void aritmetica()
{
	int num1 = NULL, aux = NULL;
	char simb = NULL;
			
	fflush(stdin);
	fscanf(stdin,"%i",&num1);
	do
	{
		do
		{
			fflush(stdin);
			fscanf(stdin,"%c",&simb);
			if(simb == '=') break;
		}while(simb != '+' && simb != '-' && simb != '/' && simb != ':' && simb != '*' && simb != 'x' && simb != '=');
		
		switch(simb)
		{
			case '+':
				fflush(stdin);
				fscanf(stdin,"%i",&aux);
				num1 = num1 + aux;
				aux = NULL;
				break;
			case '-':
				fflush(stdin);
				fscanf(stdin,"%i",&aux);
				num1 = num1 - aux;
				aux = NULL;
				break;
			case ':':
			case '/':
				fflush(stdin);
				fscanf(stdin,"%i",&aux);
				num1 = num1 / aux;
				aux = NULL;
				break;
			case 'x':
			case 'X':
			case '*':
				fflush(stdin);
				fscanf(stdin,"%i",&aux);
				num1 = num1 * aux;
				aux = NULL;
				break;
			case '=':
				fprintf(stdout,"\n%i\n",num1);
		}
	}while(simb != '=');
}


void trigonometria()
{
	int i,j = 0,k,contador_pha = 0,contador_num = 0,contador_space = 0,resultado;
	char caso[30],razon[5],num[10],aux;
	int num_resl;
	do
	{
		fflush(stdin);
		fgets(caso,30,stdin);
		for(i = 0; caso[i] != '\0'; i++)
		{
			if(isalpha(caso[i]) != 0)
			{
				caso[i] = tolower(caso[i]);
			}
			else continue;
		}
		
		i = 0;
		while(caso[i] != '\0')
		{
			printf("%i, ",i);
			if(isspace(caso[i]) != 0)
			{
				for(k = i; caso[k] != '\0'; k++)
				{
					if(caso[k+1] == '\0')
					{
						caso[k] = '\0';
						break;
					}
					else caso[k] = caso[k+1];
				}
				if(caso[i+1] != '\0')
				{
					i = 0;
					printf("\n%s\n",caso);
					continue;
				}
			}
			i++;
		}
		
		for(i = 0; isalpha(caso[i]) != 0; i++)
		{
			razon[i] = caso[i];
			
			if(isalpha(caso[i+1]) == 0)
			{
				razon[i+1] = '\0';
			}
		}
		
		j = 0;
		for(i = 0; caso[i] != '\0'; i++)
		{
			if(isdigit(caso[i]) != 0)
			{
				num[j] = caso[i];
				j++;
				if(isdigit(caso[i+1]) == 0)
				{
					num[j] = '\0';
					break;
				}
			}
		}
		num_resl = atoi(num);
		double resultado = (num_resl*3.14)/180;
		double resultado_final;
		if(strcmp(razon,"cos") == 0)
		{
			resultado_final = cos(resultado);
			printf("\nResultado: %.2f\n",resultado_final);
		}
		if(strcmp(razon,"sen") == 0)
		{
			resultado_final = sin(resultado);
			printf("\nResultado: %.2f\n",resultado_final);
		}
		
	}while(strcmp(razon,"cos") != 0 && strcmp(razon,"sen") != 0 && strcmp(razon,"tg") != 0 && strcmp(razon,"sec") != 0 && strcmp(razon,"cotg") != 0 && strcmp(razon,"cosec") != 0); 
}














