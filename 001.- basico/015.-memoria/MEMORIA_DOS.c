#include<stdio.h>

int main(void)
{
    int numero=10020130, resultado;
    printf("INGRESE UN NUMERO...\n");
    scanf("%d",&numero);

    printf("el valor de numero ahora es: %d\n",numero);
    resultado = numero*numero;
    printf("el resultado es: %d\n",resultado);

    //mas sobre scanf()

    int a;
    float b;
    char c;
    printf("\nIngrece a, b y c separados por coma\n");
    scanf("%d,%f,%c",&a,&b,&c);

    printf("a: %d\n",a);
    printf("b: %g\n",b);
    printf("c: %c\n",c);

    printf("\nIngrece a, b y c separados por espacios\n");
    scanf("%d %f %c",&a,&b,&c);

    printf("a: %d\n",a);
    printf("b: %g\n",b);
    printf("c: %c\n",c);

    printf("\nIngrece a, b y c separados por enter\n");
    scanf("%d\n%f\n%c",&a,&b,&c);

    printf("a: %d\n",a);
    printf("b: %g\n",b);
    printf("c: %c\n",c);
    return 0;
}
