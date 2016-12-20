#include <stdio.h>
#include <time.h>
void quicksort(int *arr,int inicio,int final);

int main(int argc,char **argv) {
	int arr[100],i,aux;
	srand(time(NULL));
	for(i = 0; i < 100; i++) {
		aux = 1+rand()%((100+1)-1);
		arr[i] = aux;
	}
	for(i = 0; i < 100; i++) {
		printf("%i, ",arr[i]);
	}
	printf("\n\n");
	quicksort(arr,0,sizeof(arr)/sizeof(int)-1);
	for(i = 0; i < 100; i++) {
		printf("%i, ",arr[i]);
	}
	return 0;
}

void quicksort(int *arr,int inicio,int final) {
	int i,j,tmp,pivote;
	pivote = arr[(inicio+final)/2];
	i = inicio;
	j = final;
	do {
		while(arr[i] > pivote) {i++;}
		while(arr[j] < pivote) {j--;}
		if(i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;j--;
		}
	}while(i <= j);
	if(j > inicio) {quicksort(arr,inicio,j);}
	if(i < final) {quicksort(arr,i,final);}
}
