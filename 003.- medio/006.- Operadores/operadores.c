/*
	DE MAYOR A MENOR PRIORIDAD
		OPERADORES UNARIOS	-	ARITMETICA
	++			SUMAR 1
	--			RESTAR 1
	-			NEGATIVO UNARIO
		OPERADORES BINARIOS - ARITMETICA
	*			MULTIPLICACION
	/			DIVICION
	%			MODULO
	+			SUMA
	-			RESTA
		OPERADORES RELACIONALES
	>			MAYOR QUE
	>=			MAYOR O IGUAL
	<			MENOR
	<=			MENOR O IGUAL
	==			IGUAL
	!=			DISTINTO
		OPERADORES LOGICOS - RETORNAN UN VALOR BOOLEANO (1 PARA TRUE Y 0 PARA FALSE)
	!			NOT				EL OPERADOR NOT RETORNA EL CONTRARIO A LO QUE SE RETORNO
	&&			AND (Y)			EL OPERADOR LOGIDO AND LE DA PRIORIDAD A FALSE
	||			OR (O)			EL OPERADOR LOGIDO OR LE DA PRIORIDAD A TRUE
		OPERADOR DE ASIGNACION
	=			EL OPERADOR CON MENOS PRIORIDAD
*/
#include <stdio.h>
int main(int argc,char **argv) {
	enum{false,true};
	printf("****************************\n");	
	printf("----false = 0 - true = 1----\n");
	printf("****************************\n\n");
	
	
	printf("----------------------------\n");
	printf("---OPERADORES RELACIONALES--\n");
	printf("----------------------------\n");
	printf("10 > 5\t= %10i\n",10 > 5);
	printf("2*5 > 9\t= %10i\n",10*5 > 9);
	printf("5 > 10\t= %10i\n",5 > 10);
	printf("5 != 10\t= %10i\n",5 != 10);
	printf("5 != 5\t= %10i\n",5 != 5);
	printf("5 == 5\t= %10i\n\n",5 == 5);
	
	printf("----------------------------\n");
	printf("-----OPERADORES LOGICOS-----\n");
	printf("----------------------------\n\n");
	printf("true && false\t= %10i\n",true && false);
	printf("false && true\t= %10i\n",false && true);
	printf("false && false\t= %10i\n",false && false);
	printf("true && true\t= %10i\n\n",true && true);
	
	printf("false || false\t= %10i\n",false || false);
	printf("false || true\t= %10i\n",false || true);
	printf("true || false\t= %10i\n",true || false);
	printf("true || true\t= %10i\n\n",true || true);
	
	printf("!true = %i\n",!true);
	printf("!false = %i\n\n",!false);
	
	printf("10 > 5 && 8 < 6\t\t\t= %10i\n",10 > 5 && 8 < 6);
	printf("3 > 1 && 5 < 10\t\t\t= %10i\n",3 > 1 && 5 < 10);
	printf("!(5 < 100) && 10 < 11\t\t= %10i\n",!(5 < 100) && 10 < 11);
	printf("!(false) && !(false)\t\t= %10i\n",!false && !false);
	printf("!(5 > 1000) && !(1000 < 5)\t= %10i\n\n",!(5 > 1000) && !(1000 < 5));

	printf("1 || 1 && 0\t= %10i\n",1 || 1 && 0);
	printf("0 || 1 && 0\t= %10i\n",0 || 1 && 0);
	printf("(1 || 1) && 0\t= %10i\n",(1 || 1) && 0);
	printf("1 || (1 && 0)\t= %10i\n",1 || (1 && 0));
	printf("0 || 0 && 1\t= %10i\n",0 || 1 && 1);
	return 0;
}
