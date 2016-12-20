#include <stdio.h>

int main(void)
{
	int i=0,a=3;
	while(i<=10)
    {
        if(i == a) break;
        else i++;

        printf("i: %d\n",i);
    }
}
