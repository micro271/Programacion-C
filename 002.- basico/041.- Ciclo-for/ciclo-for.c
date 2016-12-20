/*El bucle for
	
	**Sintaxis
	
			for(inicializacion; condicion; incremento)
			{
				Instrucciones
			}

*/


int main()
{
	int i;
	printf("Ascendente\n");
	for(i = 1; i <= 10; i++)
	{
		printf("%i\n",i);
	}
	
	printf("\n\nDescendiente\n");
	for(i = 10; i >= 1; i--)
	{
		printf("%i\n",i);
	}
	
	return 0;
}
