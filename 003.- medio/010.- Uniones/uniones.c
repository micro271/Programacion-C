/*
	Una union es un area de memoria la cual se encuentra compartida por varias variables
	que pueden ser de tipo diferentes
	
	definicion de union:
		union nombre_de_la_union{
			tipo nombre1;
			tipo nombre2:
			...
			tipo nombreN;
		}
	En una union, Todas las variables comparten el mismo area de memoria
	
	union comparte {
		char		xChar;		1 BYTE'S
		short int	xShrt;		2 BYTE'S
		float		xFloat;		4 BYTE'S
		double		xDouble;	8 BYTE'S
	}xVar;
	
	La cantidad de memoria reservada por la union en el caso anterior se encuentra
	indicada por la variable que ocupe la mayor cantidad de memoria en BYTE'S
	para el caso anterior es el double de 8 byte's.
	Graficamente en byte's esto se explica asi:
		// RECORDATORIO:	CADA BYTE TIENE 8 BITS -> CADA BIT ES UN 1 O 0 (BINARIO)
	VARIABLE			MEMORIA QUE OCUPA
	xChar				00000000
	xShrt				00000000 00000000
	xFloat				00000000 00000000 00000000 00000000
	xDouble				00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
	EN FORMA COMPARTIDA:
						··························xDouble······································
						············xFloar··················
						····xShrt··········
						·xChar··
	MEMORIA				00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
*/
#include <stdio.h>
struct ACCESO {
	int cTipo;
	union {
		int iIde;		//cTipo = 1;
		char cNick[8];	//cTipo = 0;
	};
};
union COLOR {
	int rgb;
	struct{
		unsigned char blue;	//0000ff
		unsigned char green;//00ff00
		unsigned char red;	//ff0000
	};
};
int main(int argc,char **argv) {
	struct ACCESO xAcceso;
	printf("Tamaño de la union acceso: %i\n",sizeof(struct ACCESO)-sizeof(int));
	xAcceso.cTipo = 1;
	xAcceso.iIde = 456;
	
	printf("ide: %i\n",xAcceso.iIde);
	printf("nick: %s\n",xAcceso.cNick);
	
	xAcceso.cTipo = 0;
	strcpy(xAcceso.cNick,"Micro");
	printf("ide: %i\n",xAcceso.iIde);
	printf("nick: %s\n",xAcceso.cNick);
	
	union COLOR xColor;
	xColor.rgb = 0xFFFFFF;
	printf("RGB\t: %5i, %X\n",xColor.rgb,xColor.rgb);
	printf("RED\t: %5i, %X\n",xColor.red,xColor.red);
	printf("BLUE\t: %5i, %X\n",xColor.blue,xColor.blue);
	printf("GREEN\t: %5i, %X\n",xColor.green,xColor.green);
	return 0;
}
