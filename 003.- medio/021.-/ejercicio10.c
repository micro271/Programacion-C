/*decimal a binario y viceversa*/
#include <stdio.h>
#include <limits.h>
char *ABinario(int x,unsigned short int BYTS);


int main(int argc,char **argv) {
	int aux = INT_MAX,nByts,i;
	nByts = sizeof(int);
	char *bin = ABinario(aux,nByts);
	for(i = 0; i < nByts*8; i++) {
		if(i%8 == 0) {printf(" ");}
		printf("%c",bin[i]);
	}
	return 0;
}

char *ABinario(int x,unsigned short int BYTS) {
	char *bits = (char *)malloc((sizeof(char)*BYTS)*8);
	char tmp;
	short int i,j,k;
	for(i = 0; i < BYTS*8; i++) {
		bits[i] = '0';
	}
	i = 0;
	while(x > 1) {
		if(x % 2 == 0) {
			bits[i] = '0';
			x /= 2;
		} else {
			bits[i] = '1';
			x--;
			x /= 2;
		}
		i++;
	}
	bits[i] = '1';i++;
	k = (BYTS*8) - i;
	for(j = i-1; j >= 0; j--) {
		tmp = bits[j];
		bits[j] = bits[k];
		bits[k] = tmp;
		k++;
	}
	
	return bits;
}
