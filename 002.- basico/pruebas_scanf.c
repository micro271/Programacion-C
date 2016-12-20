
#include <stdio.h>
struct prueba {
	char nombre[30];
};
struct prueba *crear();
void draw(struct prueba *a);
int main(int argc,char **argv) {
	struct prueba *a;
	a = crear();
	printf("%s \n",a->nombre);
	draw(a);
}
struct prueba *crear() {
	struct prueba n;
	strcpy(n.nombre,"HOLA MUNDO!!!");
	return &n;
}
void draw(struct prueba *a) {
	printf("%s,,,",a->nombre);
}
