#include <stdio.h>
#include <time.h>
#define l 100
int *margeSotr(int *arr,int size);

int main(int argc,char **argv) {
	int *arr,i;
	arr = (int *)malloc(sizeof(int)*l);
	srand(time(NULL));
	for(i = 0; i < l; i++) {
		arr[i] = 1 + rand() % ((1000 + 1) - 1);
	}
	arr = margeSotr(arr,l);
	return 0;
}

int *margeSotr(int *arr,int size) {

}
