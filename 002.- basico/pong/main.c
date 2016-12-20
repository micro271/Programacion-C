#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc,char **argv) {
	struct GAME juego;
	juego.width = 100;
	juego.height = 24;
	juego.board = crear_matriz(juego.height,juego.width);
	juego.iniJ = 10;
	juego.finJ = 14;
	juego.iniI = 10;
	juego.finI = 14;
	juego.ballX = juego.width/2;
	juego.ballY = juego.height/2;
	
	juego.modballX = -1;
	juego.modballY = -1;
	juego.modI = -1;
	add_elements(&juego);
	
	gameloop(juego);
	liberar_mem(juego.board,juego.height);
	return EXIT_SUCCESS;
}
