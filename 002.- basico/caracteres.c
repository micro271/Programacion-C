#include <stdio.h>

int main(int argc,char **argv) {
	int i;
	for(i = 32; i <= 255; i++) {
		printf("%i. %c\n",i,i);
	}
	system("pause");
}
