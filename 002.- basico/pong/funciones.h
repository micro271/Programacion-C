#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

typedef struct GAME {
	int iniJ;
	int finJ;
	int iniI;
	int finI;
	int ballX;
	int ballY;
	int modballY;
	int modballX;
	int modI;
	int width;
	int height;
	int gol;
	char **board;
}game;

//CON ESTA FUNCION CREAMOS LA MATRIZ
char **crear_matriz(int C,int F);
//CON ESTA FUNCION AGREGAMOS LOS ELEMENTOS
void add_elements(struct GAME *juego);
//CON ESTA FUNCION DELIMITAMOS  EL CAMPO
void add_border(char **board,int C, int F);
//CON ESTA FUNCION CREAMOS LA RAQUETA JUGADOR
void add_raqueta_jug(char **board, int iniJ, int finJ,int C,int F);
//CON ESTA FUNCION CREAMOS LA RAQUETA DEL IA
void add_raqueta_ia(char **board, int iniI, int finI,int C,int F);
//CON ESTA FUNCION AGREGAMOS LA PELOTA
void add_ball(char **board,int ballX, int ballY,int C,int F);
//CON ESTA FUNCION LA PINTAMOS
void paint_board(char **board,int C,int F);
//CON ESTA FUNCION LIBERAMOS LA MEMORIA DE LA MATRIZ
void liberar_mem(char **board,int C);

void gameloop(struct GAME juego);
void draw(char **board,int C,int F);
void input(struct GAME *juego);
void update(struct GAME *juego);
#endif/*_FUNCIONES_H_*/
