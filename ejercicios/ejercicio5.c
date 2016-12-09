/*
	Calcular matriz 3x3 adjunta
*/
#include <stdio.h>
#include <time.h>
int main(int argc,char **argv) {
	int f,f_2,c,c_2,i,x,y,matriz[3][3],adjunta[3][3],aux[2][2];
	srand(time(NULL));
	for(f = 0; f < 3; f++) {
		for(c = 0; c < 3; c++) {
			matriz[f][c] = 1 + rand() % ((2 + 1) - 1);
			printf("matriz[%i][%i]\t: %i\n",f,c,matriz[f][c]);
		}
	}
	printf("\n");
	i = 0;f = 0;c = 0;
	while(i <= 9) {
		y = 0;x = 0;
		f_2 = 0;
		while(f_2 < 3) {
			c_2 = 0;			
			
			while(c_2 < 3) {
				
				if(f_2 == f) {
					break;
				} else if(c_2 != c) {
					aux[x][y] = matriz[f_2][c_2];
					y++;
					if(y == 2) {y = 0;x++;}
				}
				c_2++;
				
			}
			
			
			f_2++;
		}

		
		
		adjunta[f][c] = aux[0][0] * aux[0] [1] - aux[1][0] * aux[1][1];
		printf("adjunta[%i][%i]\t: %i\n",f,c,adjunta[f][c]);
		c++;
		if(c == 3) {c = 0;f++;}

		i++;
	}
	return 0;
}
