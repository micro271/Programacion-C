#include <stdio.h>
int main(void)
{
    int i,x=0;
    for(i = 0; i <= 10; i++)
    {
        printf("Ciclo for => i: %d\n",i);
    }

    while(x <= 10)
    {
        printf("Ciclo While => x: %d\n",x++);
    }

    int z,m;
    for(z = 0, m = 0; z <= 10 && m <= 100; z++,m+=10)
    {
        printf("z: %d m: %d\n",z,m);
    }

}
