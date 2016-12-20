#include<stdio.h>
#include<string.h>

void imprimir();
int main(void)
{
	char elegir;
	do{
		mis_animes anime = agregar();
		imprimir();
		printf("Desea continuar(s/n)?: ");
		fflush(stdin);
		scanf("%c",&elegir);
		while(elegir != 's' && elegir != "S" && elegir != 'n' && elegir != 'N')
		{
			printf("Caracter incorrecto. Desea continuar(s/n): ");
			fflush(stdin);
			scanf("%c",&elegir);
		}
	}while(elegir =='s' || elegir =='S');
	
	return 0;
}

//		** typedef struct animes mis_animes; vieja manera

typedef struct animes{
	char favorito[40];
	char ultimoVisto[40];
	int cuantos;
	
}mis_animes;

mis_animes agregar()
{
	//creamos la extencion del struct
	mis_animes anime;
	
	//agregamos nuestro favorito
	printf("Cual es tu anime favorito: ");
	fflush(stdin);
	gets(anime.favorito);
	
	//agregamos el ultimo
	printf("Cual fue el ultimo anime que viste: ");
	fflush(stdin);
	gets(anime.ultimoVisto);
	
	//agregamos cuantos vimos
	printf("Cuantos animes aproximadamente viste: ");
	fflush(stdin);
	scanf("%i",&anime.cuantos);
	
	return anime;
}

void imprimir()
{
	mis_animes anime;
	printf("\nAnime favorito: %s\n",anime.favorito);
	printf("Ultimo anime visto: %s\n",anime.ultimoVisto);
	printf("Has visto: %d\n",anime.cuantos);
}

