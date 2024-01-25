#include <stdio.h>
/*
Este programa fue creado por gabriel rivas 
si lo copias recuerda borrar este cacho o cambiarle el nombre jejej
*/

int main() {
    int a, b, c, d, temp;
    printf("Este programa ordena 4 numeros de menor a mayor sin usar bubble sort\n");

    // Leer los cuatro números
    printf("Ingrese el primer n%cmero: ",163);
    scanf("%d", &a);

    printf("Ingrese el segundo n%cmero: ",163);
    scanf("%d", &b);

    printf("Ingrese el tercer n%cmero: ",163);
    scanf("%d", &c);

    printf("Ingrese el cuarto n%cmero: ",163);
    scanf("%d", &d);

    // Comparaciones para ordenar de menor a mayor
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    } else{
    	if (b > c) {
        temp = b;
        b = c;
        c = temp;
    	}
    	else{		
    		if(c > d) {
        	temp = c;
        	c = d;
        	d = temp;
			}
   	 	}
	}
	   	
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    } else{
    	if (b > c) {
        temp = b;
        b = c;
        c = temp;
    	}
	}
	
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    // Imprimir los números ordenados
    printf("N%cmeros ordenados de menor a mayor: %d, %d, %d, %d\n",163, a, b, c, d);
    return 0;
}

