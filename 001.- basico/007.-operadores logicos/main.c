#include<stdio.h>
int main(void)
{
    printf("Mismos operadores logicos que en javascript \n");

    int a=3,b=5,c=10,resultado;
    resultado = (a < b) && (b > c);
    printf("a: %d < %d :b && b: %d > %d :c -> resultado: %d \n",a,b,b,c,resultado);
    resultado = (a < b) || (b < c);
    printf("a: %d < %d :b || b: %d < %d :c -> resultado: %d",a,b,b,c,resultado);
    return 0;
}
