#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **assign();//CREAMOS EL TABLERO Y COLOCAMOS SUS POSICIONES
char assign_pos(int i);//ES UTILIZADA POR LA FUNCION QUE CREA EL TABLERO PARA INTERCAMBIAR VALORES;
void printing_board(char **board);//IMPRIMIMOS EL TABLERO Y LE DAMOS FORMATO AL JUEGO 3 EN RAYA
void artificial_intelligence(char **boar,char ficha_ia,char ficha_usr);//LAS ELECCIONES QUE REAALIZARA LA MAQUINA DEPENDIENDO DE LO QUE EL JUGADOR ELIJA
char assign_symbol();//LE ASIGNAMOS UNA FICHA AL USUARIO Y A LA MAQUINA;


int main(int argc,char **argv)
{
	char **board = NULL, pos_ia, pos_usr;
	board = assign();
	pos_usr = assign_symbol();
	if(pos_usr == 'X')
	{
		pos_ia = 'O';
	}
	else if(pos_usr = 'O')
		pos_ia = 'X';

	printing_board(board);


	/*		LIBERAMOS TODO LA MEMORIA USARA POR EL PROGRAMA 		*/
	int c,f;
	for(c = 0; c < 3; c++)
		free(*(board+c));
	free(board);
	
	return EXIT_SUCCESS;
}

char assign_symbol()//ASIGNAMOS LA FICHA QUE LE TOQUE AL USUARIO
{
	char aux;
	int x;
	x = 1 + rand() % ((2 + 1) - 1);
	switch(x)
	{
		case 1: aux = 'X';break;
		case 2: aux = 'O';break;
	}
	return aux;
}

void printing_board(char **board)
{
	int i,f=0,c=0;
	for(c = 0; c < 3; c++)
		for(f = 0; f < 3; f++)
		{
			if(f == 0)
				printf("\n\t\t%c | ",board[c][f]);
			else if(f == 1)
				printf("%c | ",*(*(board+c)+f));
			else
			{
				printf("%c\n",board[c][f]);
				if(c < 2) printf("\t\t--+---+--");
			}
		}
}

char **assign()//ASIGNAMOS LA MEMORIA PARA LA MATRIZ Y SUS HIJOS
{
	char **aux;int i,c=0,f=0,k;
	aux = (char **)malloc(sizeof(char *)*3);
	if(aux == NULL)
	{
		printf("NO SE ASIGNO MEMORIA ALA MATRIZ DEL TABLERO\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < 3; i++)
	{
		if((aux[i] = (char *)malloc(sizeof(char)*4)) == NULL)
		{
			printf("NO SE PUDO ASIGNAR MEMORIA PARA AUX[%i]",i);
			for(k = i-1; k >= 0; k--)
			{
				free(*(aux+k));//SI FALLA EN LA ASIGNACION DE MEMORIA DE ALGUNA DE LOS PUNTEROS LIBERAMOS LAS MEMORIAS ANTERIORES Y A PADRE
			}
			free(aux);
			exit(EXIT_FAILURE);
		}
	}
	
	for(i = 0; i < 3; i++)
		aux[i][3] = '\0';//LE COLOCAMOS UN FINAL A CADA SELDA
	i = 1;
	while(i <= 9)
	{
		*(*(aux+c)+f) = assign_pos(i);
		f++;
		i++;
		if(i == 4 || i == 7)
		{
			f = 0;
			c++;
		}
	}
	return aux;
}

char assign_pos(int i)//INTERCAMBIAMOS ENTEROS POR CARACTERES; ESTA FUNCION ES USADA EN LA CREACIO DEL TABLERO;
{
	char aux;
	switch(i)
	{
		case 1:aux = '1';break;
		case 2:aux = '2';break;
		case 3:aux = '3';break;
		case 4:aux = '4';break;
		case 5:aux = '5';break;
		case 6:aux = '6';break;
		case 7:aux = '7';break;
		case 8:aux = '8';break;
		case 9:aux = '9';break;
	}
	return aux;
}
