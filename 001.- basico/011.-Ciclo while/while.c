#include<stdio.h>

int main(void)
{
    int x=0,y=10;
    char output;
    while(x <= y)
    {
        if(x%2 == 0)
            output = 'p';
        else if(x%2 != 0)
            output = 'i';

        printf("%d -> %c\n",x,output);
        x++;
    }
    return 0;
}
