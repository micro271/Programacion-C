/*
	Crear una estructura con la siguiente informacion: Nombre del equipo, partidos ganados, partidos empatados,
	partidos perdidos, goles a favor y goles en contra. se debe capturar la informacion de 10 equipos. Al finalizar
	la captura de los 10 equipos los debe mostrar ordenados de mejor a peor considerando los siguientes criterios:
	partido ganado 3 puntos, partidos empatados 1 punto, partidos perdidos 0 puntos; caso de que haya empatado
	en puntos el criterio de desempate es el que tenga mayor diferencia entre goles y goles en contra. Si el empate
	persiste el siguiente criterio es el que tenga mas goles a favor
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct EQUIPO {
	short int PGanados;
	char nombre[50];
	short int PEmpatados;
	short int PPerdidos;
	short int goles_a_favor;
	short int goles_en_contra;
}Equipo;
void ORDENAR(Equipo *equipo,int inicio,int final);
int main(int argc,char **argv) {
	Equipo equipo[10],AUX;
	int i,k,j,mayor = 0,inferior;srand(time(NULL));
	strcpy(equipo[0].nombre,"Club atletico boca juniors");
	equipo[0].PGanados = 7;
	equipo[0].PEmpatados = 2;
	equipo[0].PPerdidos = 1;
	equipo[0].goles_a_favor = 10;
	equipo[0].goles_en_contra = 1;
	
	strcpy(equipo[1].nombre,"Atletico Tucuman");
	equipo[1].PGanados = 3;
	equipo[1].PEmpatados = 2;
	equipo[1].PPerdidos = 5;
	equipo[1].goles_a_favor = 7;
	equipo[1].goles_en_contra = 12;
	
	strcpy(equipo[2].nombre,"Atletico river plate");
	equipo[2].PGanados = 7;
	equipo[2].PEmpatados = 1;
	equipo[2].PPerdidos = 2;
	equipo[2].goles_a_favor = 17;
	equipo[2].goles_en_contra = 11;
	
	strcpy(equipo[3].nombre,"San martin");
	equipo[3].PGanados = 6;
	equipo[3].PEmpatados = 4;
	equipo[3].PPerdidos = 0;
	equipo[3].goles_a_favor = 11;
	equipo[3].goles_en_contra = 6;
	
	strcpy(equipo[4].nombre,"Club atletico independiente");
	equipo[4].PGanados = 3;
	equipo[4].PEmpatados = 5;
	equipo[4].PPerdidos = 2;
	equipo[4].goles_a_favor = 13;
	equipo[4].goles_en_contra = 5;
	
	strcpy(equipo[5].nombre,"Arsenal de sarandi");
	equipo[5].PGanados = 2;
	equipo[5].PEmpatados = 5;
	equipo[5].PPerdidos = 3;
	equipo[5].goles_a_favor = 21;
	equipo[5].goles_en_contra = 18;
	
	strcpy(equipo[6].nombre,"Aldosivi");
	equipo[6].PGanados = 0;
	equipo[6].PEmpatados = 6;
	equipo[6].PPerdidos = 4;
	equipo[6].goles_a_favor = 7;
	equipo[6].goles_en_contra = 15;
	
	strcpy(equipo[7].nombre,"Atletico rafaela");
	equipo[7].PGanados = 9;
	equipo[7].PEmpatados = 0;
	equipo[7].PPerdidos = 1;
	equipo[7].goles_a_favor = 17;
	equipo[7].goles_en_contra = 7;
	
	strcpy(equipo[8].nombre,"Belgrano cordoba");
	equipo[8].PGanados = 10;
	equipo[8].PEmpatados = 0;
	equipo[8].PPerdidos = 0;
	equipo[8].goles_a_favor = 21;
	equipo[8].goles_en_contra = 13;
	
	strcpy(equipo[9].nombre,"Huracan");
	equipo[9].PGanados = 10;
	equipo[9].PEmpatados = 0;
	equipo[9].PPerdidos = 0;
	equipo[9].goles_a_favor = 17;
	equipo[9].goles_en_contra = 13;
	ORDENAR(equipo,0,9);
	
	for(i = 0; i < 10; i++) {
		for(k = i+1; k < 10; k++) {
			if(equipo[i].PGanados*3+equipo[i].PEmpatados == equipo[k].PGanados*3+equipo[k].PEmpatados) {
				if(equipo[i].goles_a_favor - equipo[i].goles_en_contra < equipo[k].goles_a_favor - equipo[k].goles_en_contra) {
					strncpy(AUX.nombre, equipo[i].nombre, strlen(equipo[i].nombre) + 1);
					AUX.PGanados = equipo[i].PGanados;
					AUX.PEmpatados = equipo[i].PEmpatados;
					AUX.PPerdidos = equipo[i].PPerdidos;
					AUX.goles_a_favor = equipo[i].goles_a_favor;
					AUX.goles_en_contra = equipo[i].goles_en_contra;
					
					strncpy(equipo[i].nombre, equipo[k].nombre, strlen(equipo[k].nombre) + 1);
					equipo[i].PGanados = equipo[k].PGanados;
					equipo[i].PEmpatados = equipo[k].PEmpatados;
					equipo[i].PPerdidos = equipo[k].PPerdidos;
					equipo[i].goles_a_favor = equipo[k].goles_a_favor;
					equipo[i].goles_en_contra = equipo[k].goles_en_contra;
					
					strncpy( equipo[k].nombre , AUX.nombre , strlen( AUX.nombre ) + 1);
					equipo[k].PGanados = AUX.PGanados;
					equipo[k].PEmpatados = AUX.PEmpatados;
					equipo[k].PPerdidos = AUX.PPerdidos;
					equipo[k].goles_a_favor = AUX.goles_a_favor;
					equipo[k].goles_en_contra = AUX.goles_en_contra;
				} else if(equipo[i].goles_a_favor - equipo[i].goles_en_contra == equipo[k].goles_a_favor - equipo[k].goles_en_contra) {
					if(equipo[i].goles_a_favor < equipo[k].goles_a_favor) {
						strncpy(AUX.nombre, equipo[i].nombre, strlen(equipo[i].nombre) + 1);
						AUX.PGanados = equipo[i].PGanados;
						AUX.PEmpatados = equipo[i].PEmpatados;
						AUX.PPerdidos = equipo[i].PPerdidos;
						AUX.goles_a_favor = equipo[i].goles_a_favor;
						AUX.goles_en_contra = equipo[i].goles_en_contra;
						
						strncpy(equipo[i].nombre, equipo[k].nombre, strlen(equipo[k].nombre) + 1);
						equipo[i].PGanados = equipo[k].PGanados;
						equipo[i].PEmpatados = equipo[k].PEmpatados;
						equipo[i].PPerdidos = equipo[k].PPerdidos;
						equipo[i].goles_a_favor = equipo[k].goles_a_favor;
						equipo[i].goles_en_contra = equipo[k].goles_en_contra;
						
						strncpy( equipo[k].nombre , AUX.nombre , strlen( AUX.nombre ) + 1);
						equipo[k].PGanados = AUX.PGanados;
						equipo[k].PEmpatados = AUX.PEmpatados;
						equipo[k].PPerdidos = AUX.PPerdidos;
						equipo[k].goles_a_favor = AUX.goles_a_favor;
						equipo[k].goles_en_contra = AUX.goles_en_contra;
					}
				}
			}
		}
	}

	for(i = 0; i < 10; i++) {
		printf("Nombre: %s\n",equipo[i].nombre);
		printf("Partidos ganados: %hi\n",equipo[i].PGanados);
		printf("Partidos empatados: %hi\n",equipo[i].PEmpatados);
		printf("Partidos perdidos: %hi\n",equipo[i].PPerdidos);
		printf("Goles a favor: %hi\n",equipo[i].goles_a_favor);
		printf("Goles en contra: %hi\n\n",equipo[i].goles_en_contra);
	}
	return 0;
}

void ORDENAR(Equipo *equipo,int inicio,int final) {
	int i,j,centro,pivote;
	Equipo TMP;
	centro = (inicio+final)/2;
	pivote = (equipo+centro)->PGanados*3+(equipo+centro)->PEmpatados;
	i = inicio;
	j = final;
	do {
		while(pivote < (equipo+i)->PGanados*3+(equipo+i)->PEmpatados) {i++;}
		while(pivote > (equipo+j)->PGanados*3+(equipo+i)->PEmpatados) {j--;}
		if(i <= j) {
			strncpy( TMP.nombre, (equipo+i)->nombre, strlen( (equipo+i)->nombre ) + 1);
			TMP.PGanados = (equipo+i)->PGanados;
			TMP.PPerdidos = (equipo+i)->PPerdidos;
			TMP.PEmpatados = (equipo+i)->PEmpatados;
			TMP.goles_a_favor = (equipo+i)->goles_a_favor;
			TMP.goles_en_contra = (equipo+i)->goles_en_contra;
			
			strncpy( (equipo+i)->nombre, (equipo+j)->nombre, strlen( (equipo+j)->nombre ) + 1);
			(equipo+i)->PGanados = (equipo+j)->PGanados;
			(equipo+i)->PPerdidos = (equipo+j)->PPerdidos;
			(equipo+i)->PEmpatados = (equipo+j)->PEmpatados;
			(equipo+i)->goles_a_favor = (equipo+j)->goles_a_favor;
			(equipo+i)->goles_en_contra = (equipo+j)->goles_en_contra;
			
			strncpy( (equipo+j)->nombre, TMP.nombre, strlen( TMP.nombre ) + 1);
			(equipo+j)->PGanados = TMP.PGanados;
			(equipo+j)->PPerdidos = TMP.PPerdidos;
			(equipo+j)->PEmpatados = TMP.PEmpatados;
			(equipo+j)->goles_a_favor = TMP.goles_a_favor;
			(equipo+j)->goles_en_contra = TMP.goles_en_contra;			
			i++;j--;
		}
	}while(i <= j);
	if(i < final) {ORDENAR(equipo,i,final);}
	if(j > inicio) {ORDENAR(equipo,inicio,j);}
}
