#include <stdio.h>
#include <stdlib.h>
#define LNOMBRE 50
#define LDIRECCION 100
   typedef struct
   {
      char nombre[LNOMBRE];          /* Nombre */
      char direccion[LDIRECCION];    /* Direcci�n */
      long telefono;                 /* Tel�fono */
   } TipoDato;
/* Lee un dato desde el registro indicado */
   int leeDato(FILE *fichero, TipoDato *dato, int pos)
   {
      if(fseek(fichero,pos*sizeof(TipoDato),SEEK_SET)) 
         return 0;
      return fread(dato, sizeof(TipoDato),1,fichero)==1;
   }
/* Escribe un dato desde el registro indicado */
   int escribeDato(FILE *fichero, TipoDato *dato, int pos)
   {
      if(fseek(fichero,pos*sizeof(TipoDato),SEEK_SET)) 
         return 0;
      return fwrite(dato, sizeof(TipoDato),1,fichero)==1;
   }
/* A�ade un dato al final del fichero */
   int anadeDato(FILE *fichero, TipoDato *dato)
   {
      if(fseek(fichero,0,SEEK_END)) 
         return 0;
      return fwrite(dato, sizeof(TipoDato),1,fichero)==1;
   }
/*Programa de prueba que aleatoriamente a�ade o modifica */
   int main()
   {
      int i,nreg,anade,res;
      FILE *f;
      TipoDato d;
      if((f=fopen("listin.bin","w+b"))== NULL) 
         return 1;
   /*Muestra los datos*/
      for(i=0; ; i++)
         if(leeDato(f,&d,i)) 
            printf("Registro :%d\nNombre: %s\nDireccion: %s\nTelefono : %dl\n",
                  i+1,d.nombre,d.direccion, d.telefono);
         else 
            break;
      anade=rand()%2;
      if(anade)
         printf("Adici�n de registro\n");
      else
      {
         printf("Modificaci�n de registro\n");
         printf("N�mero de registro ");
         scanf("%d",&nreg);
         gets(d.nombre);  /* Se lee el final de l�nea que queda */
      }
      printf("Nombre "); 
      gets(d.nombre);
      printf("Direcci�n "); 
      gets(d.direccion);
      printf("N�mero de tel�fono ");
      scanf("%dl",&d.telefono);
      if(anade) 
         res=anadeDato(f,&d);
      else
         res=escribeDato(f,&d,nreg-1);
      if(!res) 
         printf("Error\n"); 
      fclose(f);
      return 0;
}
