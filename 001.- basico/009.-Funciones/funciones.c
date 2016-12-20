#include <stdio.h>

int Anime()
{
    int funcion_anime = printf("funcion anime \n");
    return funcion_anime;
}

void funcion_que_no_debuelve()
{
   printf("Esta funcion no debuelve nada \n");

}

int cuadrado(int a)
{
    a*=a;
    return a;
}

int main(void)
{
    int x,y;
    printf("funcion printf \n");
    x = Anime();
    funcion_que_no_debuelve();
    y = cuadrado(3);
    printf("%d \n",y);
    printf("%d \n",cuadrado(9));
    return 0;
}
