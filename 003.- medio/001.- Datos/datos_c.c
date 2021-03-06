#include <stdio.h>
#include <limits.h>
#include <float.h>
/*
	Tipo de datos:
	int
	char
	float
	double
	
	modificadores:
	signed		-> por default a todos lso tipos de datos
	unsigned	-> unsiged  int, unsignedchar, etc.
	long		-> long int,long double,etc.
	short		-> short int.
	
*/
int main(int argc,char **argv) {
	//LIBRERIA LIMITS -INICIO
	printf("\tLimites del dato char\n");
	printf("Limite inferior char: %i\n",CHAR_MIN);				// char
	printf("Limite superior char: %i\n",CHAR_MAX);				// char
	printf("Limite superior unsigned char: %i\n",UCHAR_MAX);	// unsigned char

	printf("\n\tLimites del dato int\n");
	printf("Limite inferior 'int': %i\n",INT_MIN);								// INT
	printf("Limite superior 'int': %i\n",INT_MAX);								// INT
	printf("Limite superior 'unsigned int': %u\n",UINT_MAX);					// UNSIGNED INT
	printf("Limite inferior 'short int': %hi\n",SHRT_MIN);						// SHORT INT
	printf("Limite superior 'short int': %hi\n",SHRT_MAX);						// SHORT INT
	printf("Limite superior 'unsigned short int': %hu\n",USHRT_MAX);			// UNSIGNED SHORT INT
	printf("Limite inferior 'long int': %li\n",LONG_MIN);						// LONG INT
	printf("Limite superior 'long int': %li\n",LONG_MAX);						// LONG INT
	printf("Limite superior 'unsigned long int': %lu\n",ULONG_MAX);				// UNSIGNED LONG INT
	printf("Limite inderior 'long long int': %lli\n",LLONG_MIN);				// LONG LONG INT
	printf("Limite superior 'long long int': %lli\n",LLONG_MAX);				// LONG LONG INT
	printf("Limite superior 'unsigned long long int': %llu\n",ULLONG_MAX);		// UNSIGNED LONG LONG INT
	
	//LIBRERIA LIMITS FINAL
	
	//LIBRERIA FLOAT INICIO
	printf("\n\tLimites del dato float\n");
	printf("Limite inferior float: %e\n",FLT_MIN);	//float
	printf("Limite superior float: %e\n",FLT_MAX);	//float
	
	printf("\n\tLimites del dato double\n");
	printf("Limite inferior double: %e\n",DBL_MIN);			// double
	printf("Limite superior double: %e\n",DBL_MAX);			// double
	printf("Limite inferior long doubler: %e\n",LDBL_MIN);	// long double
	printf("Limite superior long double: %e\n",LDBL_MAX);	// long double
	//LIBRERIA FLOAT FINAL
	printf("\nLimite superior del buffer: %i",BUFSIZ);
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
