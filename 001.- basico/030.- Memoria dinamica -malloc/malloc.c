/*
	**Memoria dinamica
	malloc, free, realloc
	malloc		->	Sirve para reservar un espacio en memoria y poder modificarla
	free		->	sirve para borrar la memoria ya reserbada;
	realloc		->	Sirve para modificar el tamaño de los vectores y arrats;
*/


int main()
{
	void * p1 = malloc(sizeof(int));
	//Si esta llena la memoria dinamica malloc debuelve un null;
	
	int * p1_a_int = (int* )p1;
	*p1_a_int = 45;
	printf("%i\n",*p1_a_int);
	
	free(p1);
	printf("%i",*p1_a_int);
	

	return 0;
}
