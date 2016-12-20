#include <stdio.h>
#include <string.h>
struct FECHA{
	int dia;
	int mes;
	int anio;
};

struct DOMICILIO{
	char calle[50];
	int numero_de_casa;
};

struct ALUMNO {
	struct DATOS{
		char nombre[50];
		char apellido[50];
		int edad;
	}Datos;
	int cx;
	struct FECHA Nacimiento;
	struct DOMICILIO Domicilio;
};

int main(int argc,char **argv) {
	struct ALUMNO als[3];
	strcpy(als[0].Datos.nombre,"Manuel Matias");
	strcpy(als[0].Datos.apellido,"Zelaya");
	als[0].Datos.edad = 21;
	als[0].cx = 39145;
	als[0].Nacimiento.dia = 30;
	als[0].Nacimiento.anio = 1995;
	als[0].Nacimiento.mes = 10;
	strcpy(als[0].Domicilio.calle,"Alem");
	als[0].Domicilio.numero_de_casa = 130;
	
	strcpy(als[1].Datos.nombre,"Maria Graciela");
	strcpy(als[1].Datos.apellido,"Zelaya");
	als[1].Datos.edad = 30;
	als[1].cx = 43673;
	als[1].Nacimiento.dia = 10;
	als[1].Nacimiento.anio = 1986;
	als[1].Nacimiento.mes = 5;
	strcpy(als[1].Domicilio.calle,"Alem");
	als[1].Domicilio.numero_de_casa = 130;
	
	strcpy(als[2].Datos.nombre,"Romina Giselle");
	strcpy(als[2].Datos.apellido,"Zelaya");
	als[2].Datos.edad = 23;
	als[2].cx = 54785;
	als[2].Nacimiento.dia = 10;
	als[2].Nacimiento.anio = 1993;
	als[2].Nacimiento.mes = 8;
	strcpy(als[2].Domicilio.calle,"Alem");
	als[2].Domicilio.numero_de_casa = 130;
	
	printf("Nombre: %s %s\n",als[0].Datos.nombre,als[0].Datos.apellido);
	printf("Edad: %i\n",als[0].Datos.edad);
	printf("CX: %i\n",als[0].cx);
	printf("Domicilio: %s %i\n",als[0].Domicilio.calle,als[0].Domicilio.numero_de_casa);
	printf("Fecha de nacimiento: %i/%i/%i\n",als[0].Nacimiento.dia,als[0].Nacimiento.mes,als[0].Nacimiento.anio);
	
	printf("\nNombre: %s %s\n",als[1].Datos.nombre,als[1].Datos.apellido);
	printf("Edad: %i\n",als[1].Datos.edad);
	printf("CX: %i\n",als[1].cx);
	printf("Domicilio: %s %i\n",als[1].Domicilio.calle,als[1].Domicilio.numero_de_casa);
	printf("Fecha de nacimiento: %i/%i/%i\n",als[1].Nacimiento.dia,als[1].Nacimiento.mes,als[1].Nacimiento.anio);
	
	printf("\nNombre: %s %s\n",als[2].Datos.nombre,als[2].Datos.apellido);
	printf("Edad: %i\n",als[2].Datos.edad);
	printf("CX: %i\n",als[2].cx);
	printf("Domicilio: %s %i\n",als[2].Domicilio.calle,als[2].Domicilio.numero_de_casa);
	printf("Fecha de nacimiento: %i/%i/%i\n",als[2].Nacimiento.dia,als[2].Nacimiento.mes,als[2].Nacimiento.anio);
	
	struct DATOS Madre;//SE PUEDE DECLARAR VARIABLES TIPO ESTRUCTURAS QUE SE ENCUENTREN DENTRO DE ESTRUCTURAS
	struct DATOS Padre;//ESTO QUEIRE DECIR Q LAS ESTRUCTURAS QUE ESNTEN DENTRO DE OTRAS SON GLOBALES
	
	strcpy(Madre.nombre,"Rosa Graciela");
	strcpy(Madre.apellido,"Gonzales de Zelaya");
	Madre.edad = 54;
	
	strcpy(Padre.nombre,"Manuel Antonio");
	strcpy(Padre.apellido,"Zelaya");
	Padre.edad = 52;
	
	printf("\nNombre Madre: %s %s",Madre.nombre,Madre.apellido);
	printf("Edad: %i\n",Madre.edad);
	
	printf("\nNombre Padre: %s %s\n",Padre.nombre,Padre.apellido);
	printf("Edad: %i\n",Padre.edad);
	/*
	struct ALUMNO new_al;
	printf("\nNombre: ");gets(new_al.Datos.nombre);
	printf("Apellido: ");fflush(stdin);gets(new_al.Datos.apellido);
	printf("Edad: ");fflush(stdin);
	if(!scanf("%i",&new_al.Datos.edad))
		new_al.Datos.edad = 0;
	printf("CX: ");fflush(stdin);scanf("%i",&new_al.cx);
	printf("Calle: ");fflush(stdin);gets(new_al.Domicilio.calle);
	printf("Numero: ");fflush(stdin);
	if(!scanf("%i",&new_al.Domicilio.numero_de_casa))
		new_al.Domicilio.numero_de_casa = 0;
	printf("Dia de nacimiento: ");fflush(stdin);scanf("%i",&new_al.Nacimiento.dia);
	printf("Mes: ");fflush(stdin);scanf("%i",&new_al.Nacimiento.mes);
	printf("Anio: ");fflush(stdin);scanf("%i",&new_al.Nacimiento.anio);
	
	printf("\nNombre: %s %s\n",new_al.Datos.nombre,new_al.Datos.apellido);
	printf("Edad: %i\n",new_al.Datos.edad);
	printf("CX: %i\n",new_al.cx);
	printf("Domicilio: %s %i\n",new_al.Domicilio.calle,new_al.Domicilio.numero_de_casa);
	printf("Fecha de nacimiento: %i/%i/%i\n",new_al.Nacimiento.dia,new_al.Nacimiento.mes,new_al.Nacimiento.anio);
	*/
	struct ALUMNO _alumno = als[1];
	
	printf("\nNombre: %s %s\n",_alumno.Datos.nombre,_alumno.Datos.apellido);
	printf("Edad: %i\n",_alumno.Datos.edad);
	printf("CX: %i\n",_alumno.cx);
	printf("Domicilio: %s %i\n",_alumno.Domicilio.calle,_alumno.Domicilio.numero_de_casa);
	printf("Fecha de nacimiento: %i/%i/%i\n",_alumno.Nacimiento.dia,_alumno.Nacimiento.mes,_alumno.Nacimiento.anio);
	
	struct ALUMNO *p_als;
	p_als = &als[0];
	// TAMBIEN ES VALIDO: p_als = als;	YA QUE EL NOMBRE TIENE LA DIRECCION DE MEMORIA DEL PRIMER ELEMENTO DEL ARRAY
	
	printf("\n-----------------------------------\n");
	printf("-------PUNTEROS A ESTRUCTURAS------\n");
	
	printf("\nNombre: %s %s\n",(*p_als).Datos.nombre,p_als->Datos.apellido);
	printf("Edad: %i\n",(*p_als).Datos.edad);
	printf("CX: %i\n",p_als[0].cx);
	printf("Domicilio: %s %i\n",p_als->Domicilio.calle,(*p_als).Domicilio.numero_de_casa);
	printf("Fecha de nacimiento: %i/%i/%i\n",(*p_als).Nacimiento.dia,(*p_als).Nacimiento.mes,p_als->Nacimiento.anio);
	
	printf("\nNombre: %s %s\n",(*(p_als+1)).Datos.nombre,(*(p_als+1)).Datos.apellido);
	printf("Edad: %i\n",(p_als+1)->Datos.edad);
	printf("CX: %i\n",p_als[0].cx);
	printf("Domicilio: %s %i\n",(*(p_als+1)).Domicilio.calle,(*(p_als+1)).Domicilio.numero_de_casa);
	printf("Fecha de nacimiento: %i/%i/%i\n",(p_als+1)->Nacimiento.dia,(p_als+1)->Nacimiento.mes,(p_als+1)->Nacimiento.anio);
	
	printf("\nNombre: %s %s\n",(*(p_als+2)).Datos.nombre,(*(p_als+2)).Datos.apellido);
	printf("Edad: %i\n",(p_als+2)->Datos.edad);
	printf("CX: %i\n",(*(p_als+2)).cx);
	printf("Domicilio: %s %i\n",p_als[2].Domicilio.calle,p_als[2].Domicilio.numero_de_casa);
	printf("Fecha de nacimiento: %i/%i/%i\n",(p_als+2)->Nacimiento.dia,(p_als+2)->Nacimiento.mes,p_als[2].Nacimiento.anio);
	return 0;
}
