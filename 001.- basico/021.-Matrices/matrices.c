#include<stdio.h>

int main(void)
{
	//Fila 1
	int matriz[2][3];
		matriz[0][0] = 1;
		matriz[0][1] = 2;
		matriz[0][2] = 3;
	//Fila 2
		matriz[1][0] = 4;
		matriz[1][1] = 5;
		matriz[1][2] = 6;
		
	int i,otraMatriz;
	i = 0;
	otraMatriz = 0;
	
	while(i < 3)
	{
		printf("Fila: %d, posicion %i -> %d \n",otraMatriz,i,matriz[otraMatriz][i]);
		if(i >= 2)
		{
			otraMatriz++;
			i = 0;
			continue;
		}
		i++;
		if(otraMatriz >= 1 && i >= 2) break;
	}
	return 0;
}
