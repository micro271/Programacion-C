#include<stdio.h>
int main()
{
    int var1,var2,resultado;
    var1 = 2;
    var2 = 11;
    //suma
    resultado = var1 + var2;
    printf("%d + %d = %d\n",var1,var2,resultado);
    //resta
    resultado = var1 - var2;
    printf("%d - %d = %d\n",var1,var2,resultado);
    //multiplicacion
    resultado = var1 * var2;
    printf("%d * %d = %d\n",var1,var2,resultado);
    //divicion
    resultado = var1 / var2;
    printf("%d / %d = %d\n",var2,var1,resultado);
    //resto
    resultado = var2%var1;
    printf("resto de %d / %d = %d",var2,var1,resultado);
    return 0;
}
