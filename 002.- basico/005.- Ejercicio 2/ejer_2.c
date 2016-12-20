//Convertir de grados celcius a grados fahrenheit

#include<stdio.h>
int aFahrenheit(int x);
int aCelcius(int x);

int main() {
	
	printf("%i\n",aFahrenheit(36));
	printf("%i",aCelcius(100));
	return 0;
}
int aFahrenheit(int x) {
	return (x*9/5)+32;
}
int aCelcius(int x) {
	return (x-32)*5/9;
}
