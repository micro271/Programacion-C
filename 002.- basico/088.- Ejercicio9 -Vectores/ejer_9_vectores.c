// Sumar 2 matrices

#include<stdio.h>
void sumar(int a[2][2], int b[2][2]);
int main()
{
	int matriz1[2][2] = {{2,1},{1,2}};
	int matriz2[2][2] = {{1,2},{2,1}};
	
	sumar(matriz1,matriz2);
	return 0;
}

void sumar(int a[2][2], int b[2][2])
{
	int suma[2][2];
	int c = 0,f;
	for(f = 0; f <=2; f++)
	{
		if(f == 2)
		{
			f = 0;
			if(c == 1)
			{
				break;
			}
			else c++;
		}
		suma[c][f] = a[c][f] + b[c][f];
	}
	c = 0;
	for(f = 0; f <=2; f++)
	{
		if(f == 2)
		{
			f = 0;
			if(c == 1)
			{
				break;
			}
			else c++;
		}
		printf("suma(%i + %i) %i\n",a[c][f],b[c][f],suma[c][f]);
	}
}
