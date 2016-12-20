#include<stdio.h>
int main(void)
{
    printf(" mismos operadores logicos que en javascript\n");
    printf(" 0 = Falso, 1 = Verdadero \n\n");
    int a = 3, b = 5, c = 3,resultado;
    resultado = (a > b);
    printf("a: %d > %d :b -> resultado: %d \n",a,b,resultado);
    resultado = (a >= c);
    printf("a: %d >= %d :c -> resultado: %d \n",a,c,resultado);
    resultado = b > c;
    printf("b: %d > %d :c -> resultado: %d \n",b,c,resultado);
    resultado = b != c;
    printf("b: %d != %d :c -> resultado: %d \n",b,c,resultado);
    resultado = c != a;
    printf("c: %d != %d :a -> resultado: %d",c,a,resultado);
    return 0;
}
