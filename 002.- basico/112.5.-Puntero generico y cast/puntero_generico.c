#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int x = 1 + rand() % ((1000 + 1) - 1);
	x = 10;
	void * puntero_x;
	puntero_x = &x;
	printf("%i\n",* (int * ) puntero_x);
	
	*(int * ) puntero_x += 30;
	printf("%i\n",* (int * ) puntero_x);
	int y = 10;
	
	system("pause");
	return 0;
}

