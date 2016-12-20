#include <stdio.h>
//Limpiar buffer

int main(void)
{
    int a;
    int b;
    printf("INGRESE EL VALOS DE A ...\n");
    fflush(stdin);
    scanf("%d",&a);
    fflush(stdin);
    printf("\nINGRESE EL VALOR DE B... \n");
    scanf("%d",&b);
    fflush(stdin);
    printf("\na = %d\n",a);
    printf("b = %d\n",b);

    system("pause");
    return 0;
}
