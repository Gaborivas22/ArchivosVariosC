#include <stdio.h>
/*
Este programa fue creado por gabriel rivas 
si lo copias recuerda borrar este cacho o cambiarle el nombre jejej
*/

int main() {
    float r, p;
    const float pi = 3.1415;
    printf("Este programa calcula el perimetro de un circulo\n");
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &r);
    p = 2 * pi * r;
    printf("El perimetro del circulo es: %.2f\n", p);
    return 0;
}

