#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"
void gameloop(struct GAME juego) {
	juego.gol = 0;
	do {
		draw(juego.board,juego.height,juego.width);//DIBIJAR
		input(&juego);//VERIFICAR Y MODIFICAR
		update(&juego);//ACTUALIZAR
		Sleep(10);
	}while(juego.gol == 0);
}
void draw(char **board,int C,int F) {
	system("cls");
	paint_board(board,C,F);
}
void update(struct GAME *juego) {
	
}
void input(struct GAME *juego) {
	int i,x = 0, y = 5;
	if(juego->ballY == 1 || juego->ballY == juego->height - 1) {
		juego->modballY *= -1;
	}
	else if(juego->ballX == 4) {
		if(juego->ballY >= juego->iniJ && juego->ballY <= juego->finJ) {juego->modballX*= -1;}
	}
	else if(juego->ballX == juego->width - 5) {
		if(juego->ballY >= juego->iniI && juego->ballY <= juego->finI) {juego->modballX *= -1;}
	}
	else if(juego->ballX == 1 || juego->ballX == juego->width -2) {
		juego->gol++;
	}
	
	for(i = 0; i <= juego->width - 5 && juego->modballX > 0; i++) {
		x = juego->ballX+1;
	}
	
	if(juego->ballY == 1 &&) {
		
	}
	
}
char **crear_matriz(int C,int F) {
	char **aux;
	int j,i;
	aux = (char **)malloc(sizeof(char *)*C);
	if(aux == NULL) {
		printf("\n**No hay espacio en memoria");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < C; i++) {
		*(aux+i) =(char *)malloc(sizeof(char)*(F+1));
		if(*(aux+i) == NULL) {
			for(j = i-1; j >= 0; j--) {
				free(*(aux+j));
			}
			free(aux);
			printf("\n**No hay espacio en memoria");
			exit(EXIT_FAILURE);
		}
		aux[i][F] = '\0';
	}
	return aux;
}

void add_elements(struct GAME *juego) {
	add_border(juego->board,juego->height,juego->width);
	add_raqueta_jug(juego->board,juego->iniJ,juego->finJ,juego->height,juego->width);
	add_raqueta_ia(juego->board,juego->iniI,juego->finI,juego->height,juego->width);
	add_ball(juego->board,juego->ballX,juego->ballY,juego->height,juego->width);
}
void add_border(char **board,int C, int F) {
	int i,j;
	for(i = 0; i < C; i++) {
		for(j = 0; j < F; j++) {			
			if(i == 0 && j == 0) {board[i][j] = 201;}
			else if(i == 0 && j == F-1) {board[i][j] = 187;}
			else if(i == C-1 && j == 0) {board[i][j] = 200;}
			else if(i == C-1 && j == F-1) {board[i][j] = 188;}
			else if((i == 0 || i == C-1) && j > 0 && j < F - 1) {board[i][j] = 205;}
			else if((j == 0 || j == F-1) && i > 0 && i < C-1) {board[i][j] = 186;}
			else {board[i][j] = ' ';}
		}
	}
}
void add_ball(char **board,int ballX, int ballY,int C,int F) {
	board[ballY][ballX] = 'O';
}
void add_raqueta_jug(char **board, int iniJ, int finJ,int C,int F) {
	int i,j;
	for(i = iniJ; i <= finJ; i++) {
		for(j = 2; j <= 3; j++) {
			board[i][j] = 'X';
		}
	}
}
void add_raqueta_ia(char **board, int iniI, int finI,int C,int F) {
	int i,j;
	for(i = iniI; i <= finI; i++) {
		for(j = F-4; j <= F-3; j++) {
			board[i][j] = 'X';
		}
	}
}
void paint_board(char **board,int C,int F) {
	int i,j;
	for(i = 0; i < C; i++) {
		for(j = 0; j < F; j++) {
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
}

void liberar_mem(char **board,int C) {
	int i,j;
	for(i = C-1; i >= 0; i--) {
		free(*(board+i));
	}
	free(board);
}
