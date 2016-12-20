#include<stdio.h>

int main(void)
{
    int i = 9;
    int tamanio;
    int direccion;

    tamanio = sizeof(int);
    direccion = &i;

    printf("El valor de 'i' es: %d\n",i);
    printf("El tamaño de 'int' es: %d bits\n",tamanio);
    printf("La direccion de 'i' es: %d",direccion);

    int contador = 0;
    while(contador <= 10)
    {
        tamanio = sizeof(int);
        direccion = &contador;
        printf("contador: %d, tamaño : %d bits, direccion: %d \n",contador++,tamanio,direccion);
    }
}
