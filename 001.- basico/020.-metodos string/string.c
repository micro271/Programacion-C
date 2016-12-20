#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char emision[] = "Kono biyutsubo";
	char anime[] = "Clannad after story";
	char copiado[] = "Sousei no onmiuoji";
	printf("Anime faborito: %s\n",anime);
	printf("Anime favorito en emision: %s\n",emision);
	
	//Copiar lo que hay en una variable y pegarla en otra reemplazando la ya existente
	//strcpy(variable-reemplazada,variable-a-la-cual-se-copio-el-contenido);
	strcpy(emision,copiado);
	printf("Reemplazo lo que hay en emision por lo que hay en copiado -> %s\n",emision);
	printf("Variable copiado -> %s\n",copiado);
	printf("Variable emision -> %s\n",emision);
	
	//Cuenta la cantidad de caracteres que hay dentro de cada variable empezando desde 1
	printf("Longitud de anime -> %d \n",strlen(anime));
	printf("Longitud de copiado -> %d\n",strlen(copiado));
	printf("Longitud de emision: %d\n",strlen(emision));
	
	//Concatenar dos variables string;
	//strcat(var-intacta,vaiable-que-se-colocara-al-final);
	char primero[] = "Mi ultimo anime favorito es: ";
	char ultimo[] = "Suki tte li na yo";
	strcat(primero,ultimo);
	printf("%s\n",primero);
	
	//Concatena n primeros numeros de caracteres;
	//strcat(var-intacta,vaiable-que-se-colocara-al-final,n characters)
	char titulo[50],subtitulo[50];
	strcpy(titulo,"Bienvenidos a Mundo Anime ");
	strcpy(subtitulo,"Muchos animes veremos \n");
	
	printf("\n%s\n",titulo);
	printf("%s",subtitulo);
	strncat(titulo,subtitulo,strlen(subtitulo));
	printf("\n%s",titulo);
	
	//Busca un caracter entre todo el string;
	//strchr(la-cadena-que-se-le-va-a-buscar-la-letra,la-letra);
	const char saludo[] = "Bienvenido a mi curso de c\n";
	const char b = 'B';
	if(strchr(saludo,b)) printf("Si se encuentra la letra %c\n",b);
	if(strchr(saludo,'m')) printf("Si se encuentra la letra m \n");
	const char m = 'c';
	char *ret; 
	ret = strchr(saludo,m);
	printf("Despues del string '%c' esta - '%s'",b,ret);
	
	
	return 0;
}
