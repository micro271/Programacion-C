#include<stdio.h>
#include<stdlib.h>


int main(int argc,char** argv)
{
	int v[5] = {4,1,2,5,6};
	int *v_2;
	int *v_3;
	v_2 = v+2;
	v_3 = v+4;
	printf("v_2: %i\tv_3: %i",*v_2,*v_3);
	v_2++; //SOLO SIRVE CON ++ SI LE SUMAS 1 COMO V_2+1 NO SIRVE;
	v_3--;//SOLO SIRVE CON -- SI LE RESTAS 1 COMO V_2-1 NO SIRVE;
	printf("\nv_2: %i\tv_3: %i",*v_2,*v_3);
	v_2++; //SOLO SIRVE CON ++ SI LE SUMAS 1 COMO V_2+1 NO SIRVE;
	v_3--;//SOLO SIRVE CON -- SI LE RESTAS 1 COMO V_2-1 NO SIRVE;
	printf("\nv_2: %i\tv_3: %i",*v_2,*v_3);
	

	return 0;
}
