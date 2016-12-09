/*
	Hacer un programa que simule un juego de dados conocido como craps de acuerdo a las siguientes reglas:
		*el jugador tira dos dados, cada dado tiene seis caras. Las caras tienen 1,2,3,4,5 y 6 caras
		*en cada tirada se suman los puntos de los 2 dados
		*si en la primera tirada suma 7 u 11 el jugador gana
		*si a la primera tirada se suman 2, 3 o 12, el jugador pierde
		*si a la primera tirada suma cualquiera de las restantes posivilidades, se seguira tirando el dado
		hasta que el jugador gane o pierda
*/
#include <stdio.h>
#include <time.h>

int main(int argc,char **argv) {
	short int dadoUno,dadoDos,suma,i = 0;
	short int flag = 1;
	srand(time(NULL));
	do {
		i++;
		dadoUno = 1 + rand() % ((6 + 1) - 1);
		dadoDos = 1 + rand() % ((6 + 1) - 1);
		suma = dadoUno+dadoDos;
		printf("intento %hi = %hi\n",i,suma);
		if(suma == 7 || suma == 11 || suma == 2 || suma == 3 || suma == 12) {
			flag = 0;
		}
	}while(flag);
	if(suma == 7 || suma == 11 || suma == 2) {
		printf("\nPERDISTE :c\n");
	} else {
		printf("\nGANASTE c:\n");
	}
	return 0;
}
