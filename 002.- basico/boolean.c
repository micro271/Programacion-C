#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool bigger(int a, int b);

int main()
{
    int a = 5, b = 2;


    if(bigger(a,b) == true)
    	printf("%i es mayor que %i",a,b);

    return 0;
}

bool bigger(int a, int b)
{
    if(a>b)
   		return 1;
    else
    	return 0;
	
}
