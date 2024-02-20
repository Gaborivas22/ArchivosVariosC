#include <stdio.h>
#include <string.h>

int numProductos=0;

// Definición de la estructura para almacenar un contacto
struct Contacto {
    char nombre[50];
    char numProduc[20];
};

// Función para añadir un contacto al arreglo
void agregarContacto(struct Contacto agenda[], int *numContactos) {
    if(numProductos==5){
       printf("no hay más espacio para agregar productos");
    }
    else{
       printf("Ingrese el nombre del producto: ");
       scanf(" %[^\n]", agenda[*numContactos].nombre);
       printf("Ingrese el número de productos disponibles: ");
       scanf("%s", agenda[*numContactos].numProduc);
    
       (*numContactos)++;
       numProductos++;
       printf("Producto agregado con éxito.\n");
    }   
}

// Función para ver todos los contactos almacenados
void verContactos(struct Contacto agenda[], int numContactos) {
    if (numContactos == 0) {
        printf("No hay productos almacenados.\n");
    } else {
        printf("Lista de productos:\n");
        for (int i = 0; i < numContactos; i++) {
            printf("Nombre: %s, Cantidad: %s\n", agenda[i].nombre, agenda[i].numProduc);
        }
    }
}

int main() {
    struct Contacto agenda[3];  // Suponemos un máximo de 100 contactos
    int numContactos = 0;
    int opcion;

    do {
        printf("\nMenú:\n");
        printf("1. Añadir producto\n");
        printf("2. Ver productos\n");
        printf("3. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarContacto(agenda, &numContactos);
                break;
            case 2:
                verContactos(agenda, numContactos);
                break;
            case 3:
                printf("Saliendo del programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    } while (opcion != 3);

    return 0;
}
