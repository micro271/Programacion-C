#include <stdio.h>

int main(void)
{
    int i;
    for(i = 0; i <= 10; i++)
    {
        if(i == 6) continue;
        printf("Hola i vale: %d\n",i);
    }
    return 0;
}
