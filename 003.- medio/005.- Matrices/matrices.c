#include <stdio.h>
int f,c,k;
int main(int argc,char **argv) {
	
	int intMatriz[2][4] = 	{	{00,01,02,03},
								{10,11,12,13}
							};
	printf("Matriz de enteros\n");
	for(f = 0; f < 2; f++) 
		for(c = 0; c < 4; c++)
			printf("intMatriz[%i][%i] = %10i\n",f,c,intMatriz[f][c]);
			
	char charMatriz[3][20] =	{
									{"Dennis Ritchie"},
									{'V','i','n','t',' ','C','e','r','f','\0'},
									{"Robert Khan"}
								};
								
	printf("\n\nMatriz de cadenas de caracteres\n");
	for(f = 0; f < 3; f++)
		printf("charMatriz[%i] = %20s\n",f,charMatriz[f]);
		
	int intMatriz_n[3][3][4] =	{
									{	{000,001,002,003},{010,011,012,013},{020,021,022,023}	},
									{	{100,101,102,103},{110,111,112,113},{120,121,122,123}	},
									{	{200,201,202,203},{210,211,212,213},{220,221,222,223}	}
								};
	printf("\n\nMatriz multi-dimencional \n");
	for(f = 0; f < 3; f++)
		for(c = 0; c < 3; c++)
			for(k = 0; k < 4; k++)
				printf("IntMatriz_n[%i][%i][%i] = %+10i\n",f,c,k,intMatriz_n[f][c][k]);
	
	char charMatriz_fam[2][3][10] =	{
										{"Antonio","Rosa","Maria"},
										{"Romina","Matias","Ximena"}
									};
	printf("\n\nMatriz fam\n");
	printf("%s\n",charMatriz_fam);
	for(f = 0; f < 2; f++)
		for(c = 0; c < 3; c++)
			printf("charMatriz_fam[%i][%i] = %10s\n",f,c,charMatriz_fam[f][c]);
	return 0;
}
