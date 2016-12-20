#include<stdio.h>

int main(void)
{
    int x=10,y=13,z;

    if(x > y)
    {
        printf("x: %d > %d :y",x,y);
    }
    else if(x < y)
    {
        printf("x: %d < %d :y",x,y);
    }
    else
    {
        printf("x: %d == %d :y \n",x,y);
    }


    return 0;
}
