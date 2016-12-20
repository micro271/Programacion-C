#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct ANIME{	//ESTRUCTURA QUE CONTIENE LAS ESPECIFICACIONES DEL ANIME
	char nombre[50];	//NOMBRE DEL ANIME
	char genero[300];	//GENERO DEL ANIME
}anime;
void menu(FILE *binario,FILE *txt);// MENU DONDE CONTENDRA LAS OPCIONES QUE PODRA REALIZAR EL USUARIO
int generos_str(char *str,int elec);//AGREGAMOS LOS GENEROS DEPENDIENDO DE QUE NUMERO SELECCION EL USUARIO
bool read_animes(FILE *binario);//LEEMOS TODOS LOS ELEMENTOS GUARDADOS EN EL ARCHIVO .DAT
void ask_animes(FILE *binario,FILE *txt);//EN CASO QUE EL USUARIO QUIERA AÑADIR UN ANIME LO AGREGAMOS A LOS ARCHIVOS
bool write_anime(anime m,FILE *binario,FILE *txt);//AQUI ESCRIBIMOS LOS ANIMES YA PEDIDOS AL ARCHIVO
void clean_string(char *str);//LIMPIAMOS EL SALTO DE LINEA POR EL FIN DE STRING Y LE COLOCAMOS MAYUSCULAS DONDE DEBAN IR
int main(int argc,char **argv)
{
	FILE *bin = fopen("Listado-binario.dat","a+b");//HABRIMOS O CREAMOS UNA RCHIVO BINARIO PARA LECTURA Y ESCRITURA CON TRUNCAMIENTO
	FILE *txt = fopen("Listado-textual.txt","a+");//HABRIMOS O CREAMOS UN ARCHIVO TIPO TEXTO PARA LECTURA Y ESCRITURA CON TRUNCAMIENTO
	menu(bin,txt);//LE PASAMOS LOS ARCHIVOS QUE SERAN NECESARIOS PARA EL GUARDADO O LECTURA Q REALIZARA EL PROGRAMA
	return EXIT_SUCCESS;
}

void menu(FILE *binario, FILE *txt)
{
	int x;char preg;
	printf("1.- Ver listado de animes vistos\n");//OPCIONES
	printf("2.- Agregar anime al listado\n");
	printf("3.- Salir");
	do
	{
		printf("\nDigite una opcion (1-3): ");fflush(stdin);
		scanf("%i",&x);
	}while(x < 1 || x > 3);
	
	switch(x)
	{
		case 1:
			if(!read_animes(binario))//SI EL USUARIO QUIERE VER TODOS LOS ANIMES QUE SE ENCUENTRAN GUARDADOS. 
			{
				printf("\nNo hay animes guardados\n");//EN CASO DE QUE NO TENGA NINGUNO RETORNARA FALSO
			}
			else
			{
				menu(binario,txt);//VOLVEMOS A LLAMAR LA FUNCION MENU PARA MOSTRAR NUEVAMENTE LAS OPCIONES Y QUE EL USUARIO SIGA INTERACTUALDO CON EL PROGRAMA
			}
			break;
		case 2:
			do
			{
				ask_animes(binario,txt);//EN CASO QUE EL USUARIO QUIERA GUARDAR UN ANIME LE PEDIMOS LOS DATOS Y LOS GUARDAMOS EN LOS ARCHIVOS
				do
				{
					fflush(stdin);
					printf("\nDesea agregar otro anime(S/N): ");//LE PEDIMOS AL USUARIO SI QUIERE SEGUIR AGREGANDO ANIMES
					scanf("%c",&preg);//GUARDAMOS LA RESPUESTA DEL USUARIO SOBRE SI QUIERE O NO SEGUIR INGRESANDO ANIMES
					preg = tolower(preg);//PARA EVITAR PROBLEMAS Y QUE EL USUARIO COLOQUE EN MAYUSCULAS LO PASAMOS A MINUSCULAS PARA MENOR PROBLEMAS
				}while(preg != 's' && preg != 'n');
			}while(preg == 's');//EN CASO DE QUE QUIERA SEGUIR AÑADIENDO ESTE BUCLE SE SEGUIRA REPITIENDO
			system("cls");menu(binario,txt);
			break;
		case 3:
			fclose(binario);fclose(txt);system("exit");
			break;
	}
}
bool read_animes(FILE *binario)//LEEMOS TODOS LOS ANIMES GUARDADOS EN EL ARCHIVO BINARIO
{
	int pos = 0;
	anime aux;//ANIME AUXILIAR DONDE SE GUARDARA TEMPORALMENTE EL ELEMENTO LEIDO PARA PDOER IMPRIMIRLO
	fseek(binario,0,SEEK_SET);//COLOCAMOS EL PUNTERO EN LA POSICION 0 DEL INICIO
	system("cls");//LIMPIAMOS EL CMD
	if(fread(&aux,sizeof(anime),1,binario) != 1)//PEDIMOS EL PRIMER VALOR
		return false;
	while(!feof(binario))//MIENTRAS QUE SIGA TENIENDO ELEMENTOS SEGUIRA IMPRIMIENDO COSAS
	{
		printf("Nombre: %s\t\tGenero: %s\n\n",aux.nombre,aux.genero);//NOMBRES Y GENEROS
		fread(&aux,sizeof(anime),1,binario);
	}
	return true;// SI PUDIMOS LEER UN ARCHIVO RETORNAMIS TRUE
}
void ask_animes(FILE *binario,FILE *txt)//PEDIMOS NOMBRE Y GENERO DEL ANIME
{
	anime m;
	int n, h, k, i;
	n = 0;
	system("cls");
	do
	{
		printf("Nombre: ");fflush(stdin);//PEDIMOS NOMBRE
		fgets(m.nombre,40,stdin);//GUARDAMOS EL NOMBRE
	}while(strlen(m.nombre) < 2 || strlen(m.nombre) > 38);//QUE EL NOMBRE NO SEA DEMACIADO CORTO O CHIVO
	clean_string(&m.nombre);//LIMPIAMOS EL SALTO DE LINEA QUE COLOCA EL FGETS Y COLOCAMOS LAS RESPECTIVAS MAYUSCULAS
	
	strcpy(m.genero,"");//COLOCAMOS ESPACIO PARA PODER REALIZAR LA CONCATENIACION
	do
	{
		fflush(stdin);//LIMPIAMOS BUFFER
		system("cls");
		printf("Nombre: %s\n",m.nombre);//ARRIBA APARECERA EL NOMBRE
		printf("Generos: %s\n",m.genero);//Y EL GENERO PARA QUE EL USUARIO NO SE OLVIDE ._.'
		printf("\n1.- Romance");
		printf("\n2.- Drama");
		printf("\n3.- Comedia");
		printf("\n4.- Harem");
		printf("\n5.- Psicologico");
		printf("\n6.- Musical");
		printf("\n7.- Fantasia");
		printf("\n8.- Super poderes");
		printf("\n9.- Magia");
		printf("\n10.- Siencia ficcion");
		printf("\n11.- Ecchi");
		printf("\n12.- Hentai");
		printf("\n13.- Recuerdos de la vida");
		printf("\n14.- Mecha");
		printf("\n15.- Accion");
		printf("\n16.- Aventura");
		printf("\n17.- Deportes");
		printf("\n18.- Escolares");
		printf("\n19.- Gore");
		printf("\n20.- Horror");
		printf("\n21.- Lucha");
		printf("\n22.- Militar");
		printf("\n23.- Historico");
		printf("\n24.- Parodia");
		printf("\n0.- Salir");
		do
		{
			printf("\nSeleccione un genero: ");//HACEMOS QUE EL USUARIO COLOQUE EL NUMERO QUE REPRESENTA A CADA GENERO
			fflush(stdin);scanf("%i",&h);//GUARDAMOS LA OPCION
			if(h < 0 || h > 24 || isalpha(h) != 0)
				printf("Elija una opcion valida\n");
		}while(h < 0 || h > 24 || isalpha(h) != 0);//REVISAREMOS QUE EL USUARIO NO COLOQUE UN CARACTER O UN NUMERO QUE NO SE ENCUENTRE ENTRE LAS OPCIONES
	}while(generos_str(&m.genero,h) != 0);
	
	for(i = 0; i < strlen(m.genero); i++)//COLOCAMOS LAS COMAS DESPEUS DE CADA GENERO PARA DIFERENCIAR DE GENERO ENTRE GENERO
	{
		if(m.genero[i] == ' ' && m.genero[i+1] == ' ')//HACEMOS LA VALIDACION PARA REEMPLAZAR
		{
			m.genero[i] = ',';//REEMPLAZAMOS
		}
	}
	
	if(write_anime(m,binario,txt) == false)//ESCRIBIMOS LOS ELEMENTOS EN EL ARCHIVO BINARIO Y TEXTUAL
	{
		printf("\nHubo un error al gaurdar los datos\n");//EN CASO DE QUE ALGUNO DE LOS ELEMENTOS CAUSE UN ERROR RETORNARA FALSE
	}
}
bool write_anime(anime m,FILE *binario,FILE *txt)//ESCRIBIMOS LOS ELEMENTOS EN EL ARCHIVO
{
	if(fprintf(txt,"Nombre: %s\tGenero: %s\n",m.nombre,m.genero) < 0)//COLOCAMOS EL NOMBRE Y GENERO EN EL ARCHIVO .TXT EN CASO DE ERROR Y RETORNE UN NUMERO NEGATIVO RETORNAMOS UN FALSE
		return false;
	if( fwrite(&m,sizeof(anime),1,binario) != 1 )//SI NO SE PUEDE GUARDAR LOS ELEMENTOS EN EL ARCHIVO BINARIO RETORNARA UN NUMERO DISTINTO A LA CANTIDAD DE ARCHIVOS INTENTADOS GUARDAR
		return false;
	return true;//SI TODO SALE BIEN RETORNA TRUE
}
int generos_str(char *str,int elec)//ESTA FUNCION REVISA EL NUMERO PASADO Y COLOCA EL RESPECTIVO GENERO DEPENDIENDO DEL NUMERO INGRESADO
{
	char genero[40];int i;
	switch(elec)
	{
		case 1:strcpy(genero,"  Romance");break;
		case 2:strcpy(genero,"  Drama");break;
		case 3:strcpy(genero,"  Comedia");break;
		case 4:strcpy(genero,"  Harem");break;
		case 5:strcpy(genero,"  Psicologico");break;
		case 6:strcpy(genero,"  Musical");break;
		case 7:strcpy(genero,"  Fantasia");break;
		case 8:strcpy(genero,"  Super poderes");break;
		case 9:strcpy(genero,"  Magia");break;
		case 10:strcpy(genero,"  Siencia ficcion");break;
		case 11:strcpy(genero,"  Ecchi");break;
		case 12:strcpy(genero,"  Hentai");break;
		case 13:strcpy(genero,"  Recuerdos de la vida");break;
		case 14:strcpy(genero,"  Mecha");break;
		case 15:strcpy(genero,"  Accion");break;
		case 16:strcpy(genero,"  Aventura");break;
		case 17:strcpy(genero,"  Deportes");break;
		case 18:strcpy(genero,"  Escolares");break;
		case 19:strcpy(genero,"  Gore");break;
		case 20:strcpy(genero,"  Horror");break;
		case 21:strcpy(genero,"  Lucha");break;
		case 22:strcpy(genero,"  Militar");break;
		case 23:strcpy(genero,"  Historico");break;
		case 24:strcpy(genero,"  Parodia");break;
		case 0:return 0;
	}
	
	strcat(str,genero);
	while(isspace(*str))
	{
		for(i = 0; i <= strlen(str); i++)
		{
			*(str+i) = *(str+(i+1));
		}
	}
	return elec;
}

void clean_string(char *str)
{
	int len = strlen(str);int k = 0;int i;
	while(isspace(*str))
	{
		for(i = 0; i <= strlen(str); i++)
		{
			*(str+i) = *(str+(i+1));
		}
	}
	for(i = 0; i <= strlen(str); i++)
	{
		if(*(str+i) == '\n')
		{
			*(str+i) = '\0';break;
		}
		if(isspace(*(str+i)) && *(str+i) != '\n')
		{
			*(str+(i+1)) = toupper(*(str+(i+1)));
		}
		if(i == 0)
		{
			*str = toupper(*str);
		}
	}
}
