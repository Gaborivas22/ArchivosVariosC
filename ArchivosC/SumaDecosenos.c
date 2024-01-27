#include <stdio.h>
#include <math.h>
/*
Este programa fue creado por gabriel rivas 
si lo copias recuerda borrar este cacho o cambiarle el nombre jejej
*/
int main() {
    float x, y, A;
    printf("Este programa realiza la suma de un coseno mas un seno en terminos de radianes\n");
    printf("Ingrese el valor del coseno: ");
    scanf("%f", &x);
    printf("Ingrese el valor del seno: ");
    scanf("%f", &y);
    A = cos(x) + sin(y);
    printf("El valor de A es: %.2f\n", A);
    return 0;
}

