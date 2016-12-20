/*
	Un alumno decea saber cual es su calificacion final en la materia de algoritmos.
	Docha calificacion se compone de
	. 55% del promedio de sus 3 calificaciones parciales
	. 30% de su calificacion del examen final
	. 15% de su calificacion del trabajo final
*/

#include<stdio.h>

int main() {
	printf("Las notas van de 0 a 100\n");
	//sus 3 parciales
	float eval_1,eval_2,eval_3,promedio;
	printf("Coloca la nota de tu primer parcial: ");
	fflush(stdin);
	scanf("%f",&eval_1);
	if(eval_1 > 100) {
		printf("Nota > 100\n");
		while(eval_1 > 100) {
			printf("Coloca la nota de tu primer parcial: ");
			fflush(stdin);
			scanf("%f",&eval_1);
		}
	}
	
	printf("Coloca la nota de tu segundo parcial: ");
	fflush(stdin);
	scanf("%f",&eval_2);
	if(eval_2 > 100) {
		printf("Nota > 100\n");
		while(eval_2 > 100) {
			printf("Coloca la nota de tu segundo parcial: ");
			fflush(stdin);
			scanf("%f",&eval_2);
		}
	}
	printf("Coloca la nota de tu tercer parcial: ");
	fflush(stdin);
	scanf("%f",&eval_3);
	if(eval_3 > 100) {
		printf("Nota > 100\n");
		while(eval_3 > 100) {
			printf("Coloca la nota de tu tercer parcial: ");
			fflush(stdin);
			scanf("%f",&eval_3);
		}
	}
	promedio = (eval_1 + eval_2 + eval_3)/3;
	
	float promedio_final;
	promedio_final = (55*promedio)/100;
	
	float eval_final,promedio_final_dos;
	printf("Cuanto te sacaste en tu examen final?: ");
	fflush(stdin);
	scanf("%f",&eval_final);
	promedio_final_dos = (30*eval_final)/100;
	
	float trabajo_final,promedio_final_tres;
	printf("Cuanto te sacaste en tu trabajo final?: ");
	fflush(stdin);
	scanf("%f",&trabajo_final);
	promedio_final_tres = (15*trabajo_final)/100;
	
	float nota_final;
	nota_final = promedio_final + promedio_final_dos + promedio_final_tres;
	printf("Tu nota final es: %.1f",nota_final);
	return 0;
}











