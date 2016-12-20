/*
	hacer un arbol con '*'
	
	 *
	**
    ***
    ****
    *****
*/


#include <stdio.h>
#include <string.h>

int main()
{
	char arbol[10] = "";
	int i;
	for(i = 1; i <= 5; i++)
	{
		strcat(arbol,"*");
		printf("%s\n",arbol);
	}
	return 0;
}
