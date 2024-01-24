#include <stdio.h>
/*
Este programa fue creado por gabriel rivas 
si lo copias recuerda borrar este cacho o cambiarle el nombre jejej
*/

int main() {
    int num1, num2, resultado = 0;
    printf("Este programa resuelve la multiplicacion rusa\n");
    
    printf("Ingrese el primer n%cmero: ",163);
    scanf("%d", &num1);
    
    printf("Ingrese el segundo n%cmero: ",163);
    scanf("%d", &num2);
    
    while (num2 > 0) {
        if (num2 % 2 != 0) {
            resultado= resultado + num1;
        }
        num1 =num1* 2;
        num2 = num2/2 ;
    }
    
    printf("El resultado de la multiplicaci%cn rusa es: %d\n",162, resultado);
    
    return 0;
}


