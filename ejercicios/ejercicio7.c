/*
	Crear una estructura para capturar la siguiente informacion: nombre del alumno, las calificaciones
	(0-10) de matematicas, ingles, fisica, historia, quimica y el promedio de las 5 materia. Se debe
	capturar la informacion de 10 alumno, el promedio no se captura, el programa debe capturarl. Al
	finalizar la captura de los 10 alumnos se deben mostrar los nombres de los alumnos con promedio
	menores a 8
*/
#include <stdio.h>
#include <time.h>
#include <string.h>
typedef struct ALUMNO {
	char nombre[50];
	short int matematicas;
	short int ingles;
	short int fisica;
	short int historia;
	short int quimica;
	float promedio;
}Alumno;
int main(int argc,char **argv) {
	int i,j,cont = 0;
	Alumno alumno[10];
	srand(time(NULL));
	strcpy(alumno[0].nombre,"Naoshi Komi");
	strcpy(alumno[1].nombre,"Akira Toriyama");
	strcpy(alumno[2].nombre,"Masashi Kishimoto");
	strcpy(alumno[3].nombre,"Rumiko Takahashi");
	strcpy(alumno[4].nombre,"Yoshihiro Togashi");
	strcpy(alumno[5].nombre,"Tite Kubo");
	strcpy(alumno[6].nombre,"Naoko Takeuchi");
	strcpy(alumno[7].nombre,"Nobuhiro Watsuki");
	strcpy(alumno[8].nombre,"Eiichiro Oda");
	strcpy(alumno[9].nombre,"Shiina Karuho");
	
	for(i = 0; i < 10; i++) {
		alumno[i].matematicas = 1 + rand() % ((10 + 1) - 1);
		alumno[i].ingles = 1 + rand() % ((10 + 1) - 1);
		alumno[i].fisica = 1 + rand() % ((10 + 1) - 1);
		alumno[i].historia = 1 + rand() % ((10 + 1) - 1);
		alumno[i].quimica = 1 + rand() % ((10 + 1) - 1);
		alumno[i].promedio = (alumno[i].matematicas + alumno[i].ingles + alumno[i].fisica + alumno[i].historia + alumno[i].quimica)/5.;
		if(alumno[i].promedio < 8) {cont++;}
	}
	/*
		i = 0;
		while(i < 10) {
			printf("Nombre: ");fflush(stdin);
			fgets(alumno[i].nombre,50,stdin);
			j = 0;
			while(alumno[i].nombre[j] != '\n') {j++;}
			alumno[i].nombre[j] = '\0';
			
			printf("Matematicas (0-10): ");fflush(stdin);
			scanf("%hi",alumno[i].matematicas);
			
			printf("Ingles (0-10): ");fflush(stdin);
			scanf("%hi",alumno[i].ingles);
			
			printf("Fisica (0-10): ");fflush(stdin);
			scanf("%hi",alumno[i].fisica);
			
			printf("Historia (0-10): ");fflush(stdin);
			scanf("%hi",alumno[i].historia);
			
			printf("Quimica (0-10): ");fflush(stdin);
			scanf("%hi",alumno[i].quimica);
			
			alumno[i].promedio = (alumno[i].matematicas + alumno[i].ingles + alumno[i].fisica + alumno[i].historia + alumno[i].quimica)/5;
			if(alumno[i].promedio < 8) {cont++;}
		}
	*/
	printf("Alumnos con promedio menor a 8: %i\n",cont);	
	for(i = 0; i < 10; i++) {
		if(alumno[i].promedio < 8) {
			printf("Nombre: %s\n",alumno[i].nombre);
			printf("Matematicas: %hi\n",alumno[i].matematicas);
			printf("Ingres: %hi\n",alumno[i].ingles);
			printf("Fisica: %hi\n",alumno[i].fisica);
			printf("Historia: %hi\n",alumno[i].historia);
			printf("Promedio: %.2f\n\n",alumno[i].promedio);
		}
	}
	return 0;
}
