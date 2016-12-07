#include <stdio.h>
#include <time.h>
typedef struct JUEGO {				//LOS OBJETOS QUE NECESITA EL JUEGO
	char board[5][6];				//EL TABLERO
	char fichaUsr_1;				//LA FICHA DEL JUGADOR 1
	char fichaUsr_2;				//LA FICHA DEL JUGADOR 2
	short int puntuacionUsr_1;		//PUNTUACION DEL JUGADOR 1
	short int puntuacionUsr_2;		//PUNTUACION DEL JUGADOR 2
	short int turno;				//EL TURNO
}Juego;
//AGREGAMOS LOS ELEMENTOS QUE TENDRA EL TABLERO
void elements(Juego *juego);
//GAMELOOP
void gameloop(Juego juego);
//PINTAMOS EL TABLERO
void draw(Juego *juego);
//ACTUALIZAMOS LAS POSICIONES EN EL TABLERO Y COLOCAMOS LAS FICHAS
void update(Juego *juego,char ch);

int main(int argc,char **argv) {
	Juego juego;												//INICIALIZAMOS UNA ESTRUCTURA PARA EL JUEGO
	srand(time(NULL));											//NUMERO ALEATORIO
	int al = 1 + rand() % ((2 + 1) - 1);						//NUMERO ALEATORIO
	
	juego.fichaUsr_1 = (al == 1) ? 'X' : 'O';					//SELECCIONAMOS AL AZAR LA FICHA
	juego.fichaUsr_2 = (juego.fichaUsr_1 == 'X') ? 'O' : 'X';	//DEPENDIENDO DEL OTRO JUGADOR ESTA TIENE UNA U OTRA
	juego.puntuacionUsr_1 = 0;									//INICIALIZAMOS LA PUNTUACION A 0
	juego.puntuacionUsr_2 = 0;									//INICIALIZAMOS LA PUNTUACION A 0
	juego.turno = 0;											//TURNO 0
	elements(&juego);											//LE COLOCAMOS A LA MATRIZ LOS ELEMENTOS
	gameloop(juego);											//EL JUEGO
	return 0;
}

void gameloop(Juego juego) {
	char ch,aux;
	do {
		system("cls");
		draw(&juego);
		printf("\nPosicion: ");fflush(stdin);
		ch = getchar();
		if(ch != '\n' && (aux = getchar()) == '\n')
			update(&juego,ch);
	}while(ch != '0');
}

void draw(Juego *juego) {
	int c,f;
	for(f = 0; f < 5; f++)
		for(c = 0; c < 6; c++)
		{
			if(c == 0) {
				printf("\t");
			}
			printf(" %c",juego->board[f][c]);
		}
	printf("\n\n\t%c = %i \t %c = %i",juego->fichaUsr_1,juego->puntuacionUsr_1,juego->fichaUsr_2,juego->puntuacionUsr_2);
}

void update(Juego *juego,char ch) {
	int c_1,c_2,f,c;
	if(ch >= '1' && ch <= '9') {
		for(f = 0; f < 5; f+=2)
			for(c = 0; c < 6; c += 2) {
				if(ch == juego->board[f][c]) {
					if(juego->turno % 2 == 0) {
						juego->board[f][c] = (*juego).fichaUsr_1;
					}else {
						juego->board[f][c] = (*juego).fichaUsr_2;
					}
					juego->turno++;
				}
			}
	}
	c_1 = 0;
	c_2 = 0;
	for(f = 0; f < 5; f+=2) {
		for(c = 0; c < 6; c+=2) {
			if(juego->board[f][c] == juego->fichaUsr_1) {
				if(c_2 > 0) {
					break;
				} else {
					c_1++;
				}
			} else if(juego->board[f][c] == juego->fichaUsr_2) {
				if(c_1 > 0) {
					break;
				} else {
					c_2++;
				}
			} else {
				break;
			}
		}
		if(c_1 == 3 || c_2 == 3) {
			goto FIN;
		} else {
			c_1 = 0;
			c_2 = 0;
		}
	}
	for(c = 0; c < 5; c+=2) {
		for(f = 0; f < 6; f+=2) {
			if(juego->board[f][c] == juego->fichaUsr_1) {
				if(c_2 > 0) {
					break;
				} else {
					c_1++;
				}
			}
			else if(juego->board[f][c] == juego->fichaUsr_2) {
				if(c_1 > 0) {
					break;
				} else {
					c_2++;
				}
			}
		}
		if(c_1 == 3 || c_2 == 3) {
			goto FIN;
		} else {
			c_1 = 0;
			c_2 = 0;
		}
	}
	
	for(f = 0; f < 5; f+=2) {
		for(c = 0; c < 6; c+=2) {
			if(f == c) {
				if(juego->board[f][c] == juego->fichaUsr_1) {
					c_1++;
				} else if(juego->board[f][c] == juego->fichaUsr_2) {
					c_2++;
				}
				else {
					break;
				}
			}
		}
		if(c_1 == 3 || c_2 == 3) {
			goto FIN;
		}
	}
	
	c_1 = 0;c_2 = 0;
	f = 4;
	for(c = 0; c < 6; c+=2) {
		if(juego->board[f][c] == juego->fichaUsr_1) {
			if(c_2 > 0) {
				break;
			} else {
				c_1++;
			}
		} else if(juego->board[f][c] == juego->fichaUsr_2) {
			if(c_1 > 0) {
				break;
			} else {
				c_2++;
			}
		}
		f-=2;
	}
	FIN:
		if(c_1 == 3) {
			juego->puntuacionUsr_1++;
			elements(juego);
		}
		else if(c_2 == 3) {
			juego->puntuacionUsr_2++;
			elements(juego);
		}
}


void elements(Juego *juego) {
	char ch = '1';
	int f,c;
	for(f = 0; f < 5; f++)
	{
		for(c = 0; c < 5; c++) {	
			if(f == 1 || f == 3) {
				juego->board[f][c] = '-';
			} else if(c == 1 || c == 3) {
				juego->board[f][c] = '|';
			}else {
				(*juego).board[f][c] = ch;
				ch++;
			}
		}
		juego->board[f][5] = '\n';
	}
}
