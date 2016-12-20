#include<stdio.h>
int main()
{
    printf("mismos operadores de asignacion que javascript");
    int a = 3, b = 5;
    a++;
    printf("a: %d \n",a);
    a--;
    printf("a: %d \n",a);
    a+=b;
    printf("a+=b: %d \n",a);
    a-=b;
    printf("a-=b: %d \n",a);
    a*=b;
    printf("a*=b: %d \n",a);
    a/=b;
    printf("a/=b: %d",a);
    return 0;
}
