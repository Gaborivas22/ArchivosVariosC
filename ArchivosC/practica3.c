#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 100

struct Libro {
    char nombre[50];
    int año;
    char autor[50];
    int id;
};

void agregarLibro(struct Libro libros[], int numLibros) {
    printf("Nombre del libro: ");
    scanf("%s", libros[numLibros].nombre);

    printf("Año: ");
    scanf("%d", &libros[numLibros].año);

    printf("Autor: ");
    scanf("%s", libros[numLibros].autor);

    libros[numLibros].id = numLibros + 1;

    printf("Libro agregado con éxito.\n");
}

void mostrarLibros(struct Libro libros[], int numLibros) {
    if (numLibros == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("Lista de libros:\n");
    for (int i = 0; i < numLibros; i++) {
        printf("ID: %d, Nombre: %s, Año: %d, Autor: %s\n", libros[i].id, libros[i].nombre, libros[i].año, libros[i].autor);
    }
}

void buscarLibroPorAutor(struct Libro libros[], int numLibros) {
    char autorBuscado[50];
    printf("Ingrese el autor a buscar: ");
    scanf("%s", autorBuscado);

    int encontrado = 0;
    for (int i = 0; i < numLibros; i++) {
        if (strcmp(libros[i].autor, autorBuscado) == 0) {
            printf("ID: %d, Nombre: %s, Año: %d, Autor: %s\n", libros[i].id, libros[i].nombre, libros[i].año, libros[i].autor);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Libro no encontrado.\n");
    }
}

int main() {
    struct Libro libros[MAX_LIBROS];
    int numLibros = 0;
    char opcion;

    do {
        printf("\nMenú Consultas\n");
        printf("a) Agregar Libro\n");
        printf("b) Mostrar Libros\n");
        printf("c) Buscar libro por Autor\n");
        printf("d) Salir\n");
        printf("Seleccione una opción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'a':
                if (numLibros < MAX_LIBROS) {
                    agregarLibro(libros, numLibros);
                    numLibros++;
                } else {
                    printf("No se pueden agregar más libros. Límite alcanzado.\n");
                }
                break;
            case 'b':
                mostrarLibros(libros, numLibros);
                break;
            case 'c':
                buscarLibroPorAutor(libros, numLibros);
                break;
            case 'd':
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 'd');

    return 0;
}
