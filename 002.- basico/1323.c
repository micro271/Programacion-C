#include <stdio.h>
#include <conio.h>

int main(int argc,char **argv) {
	int i;
	char n[4];fgets(n,4,stdin);
	printf("%s\n",n);
	for(i = 0; i < 4; i++) {
		printf("%c, ",n[i]);
	}
	
	return 0;
}
