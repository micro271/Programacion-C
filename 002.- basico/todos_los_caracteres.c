#include <stdio.h>
#include <limits.h>
int main(void) {
	int i;
	for(i = CHAR_MIN; i <= CHAR_MAX; i++) {
		printf("%i -> %c\n",i,i);
	}
	system("pause");
	return 0;
}
