#include <stdio.h>
#include <conio.h>

int main(int argc,char **argv) {
	int c;
	do {
		c = getch();
		printf("%c. %i\n",c,c);
	}while(1);
	return 0;
}
