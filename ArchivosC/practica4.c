#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    char apellidoPaterno[50];
    char apellidoMaterno[50];
    int edad;
    int idUsuario;
} Usuario;

void registrarNuevoUsuario(Usuario** usuarios, int* cantidadUsuarios);
void verUsuarios(Usuario* usuarios, int cantidadUsuarios);
void modificarUsuario(Usuario* usuarios, int cantidadUsuarios);
void eliminarUsuario(Usuario** usuarios, int* cantidadUsuarios);

int main() {
    Usuario* usuarios = NULL;
    int cantidadUsuarios = 0;
    char opcion;

    do {
        printf("\nMenú Nuevo Usuario\n");
        printf("a) Registrar Nuevo Usuario\n");
        printf("b) Ver Usuarios\n");
        printf("c) Modificar Usuario\n");
        printf("d) Eliminar Usuario\n");
        printf("e) Salir\n");
        printf("Ingrese su opción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case 'a':
                registrarNuevoUsuario(&usuarios, &cantidadUsuarios);
                break;
            case 'b':
                verUsuarios(usuarios, cantidadUsuarios);
                break;
            case 'c':
                modificarUsuario(usuarios, cantidadUsuarios);
                break;
            case 'd':
                eliminarUsuario(&usuarios, &cantidadUsuarios);
                break;
            case 'e':
                // Liberar memoria antes de salir
                free(usuarios);
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Opción no válida, intente de nuevo.\n");
        }
    } while (opcion != 'e');

    return 0;
}

void registrarNuevoUsuario(Usuario** usuarios, int* cantidadUsuarios) {
    (*cantidadUsuarios)++;
    *usuarios = (Usuario*)realloc(*usuarios, (*cantidadUsuarios) * sizeof(Usuario));

    Usuario* nuevoUsuario = *usuarios + (*cantidadUsuarios) - 1;

    printf("Ingrese nombre: ");
    scanf("%s", nuevoUsuario->nombre);
    printf("Ingrese apellido paterno: ");
    scanf("%s", nuevoUsuario->apellidoPaterno);
    printf("Ingrese apellido materno: ");
    scanf("%s", nuevoUsuario->apellidoMaterno);
    printf("Ingrese edad: ");
    scanf("%d", &nuevoUsuario->edad);

    nuevoUsuario->idUsuario = *cantidadUsuarios;

    printf("Usuario registrado con éxito.\n");
}

void verUsuarios(Usuario* usuarios, int cantidadUsuarios) {
    if (cantidadUsuarios == 0) {
        printf("No hay nuevos usuarios C:\n");
    } else {
        printf("Lista de Usuarios:\n");
        for (int i = 0; i < cantidadUsuarios; i++) {
            printf("ID: %d, Nombre: %s, Apellido Paterno: %s, Apellido Materno: %s, Edad: %d\n",
                   usuarios[i].idUsuario, usuarios[i].nombre, usuarios[i].apellidoPaterno,
                   usuarios[i].apellidoMaterno, usuarios[i].edad);
        }
    }
}

void modificarUsuario(Usuario* usuarios, int cantidadUsuarios) {
    if (cantidadUsuarios == 0) {
        printf("No hay usuarios para modificar.\n");
        return;
    }

    int idModificar;
    printf("Ingrese el ID del usuario a modificar: ");
    scanf("%d", &idModificar);

    for (int i = 0; i < cantidadUsuarios; i++) {
        if (usuarios[i].idUsuario == idModificar) {
            printf("Datos antes de la modificación:\n");
            printf("ID: %d, Nombre: %s, Apellido Paterno: %s, Apellido Materno: %s, Edad: %d\n",
                   usuarios[i].idUsuario, usuarios[i].nombre, usuarios[i].apellidoPaterno,
                   usuarios[i].apellidoMaterno, usuarios[i].edad);

            printf("Ingrese nuevo nombre: ");
            scanf("%s", usuarios[i].nombre);
            printf("Ingrese nuevo apellido paterno: ");
            scanf("%s", usuarios[i].apellidoPaterno);
            printf("Ingrese nuevo apellido materno: ");
            scanf("%s", usuarios[i].apellidoMaterno);
            printf("Ingrese nueva edad: ");
            scanf("%d", &usuarios[i].edad);

            printf("Datos después de la modificación:\n");
            printf("ID: %d, Nombre: %s, Apellido Paterno: %s, Apellido Materno: %s, Edad: %d\n",
                   usuarios[i].idUsuario, usuarios[i].nombre, usuarios[i].apellidoPaterno,
                   usuarios[i].apellidoMaterno, usuarios[i].edad);

            return;
        }
    }

    printf("Usuario no encontrado.\n");
}

void eliminarUsuario(Usuario** usuarios, int* cantidadUsuarios) {
    if (*cantidadUsuarios == 0) {
        printf("Usuarios no disponibles.\n");
        return;
    }

    int idEliminar;
    printf("Ingrese el ID del usuario a eliminar: ");
    scanf("%d", &idEliminar);

    int indiceEliminar = -1;
    for (int i = 0; i < *cantidadUsuarios; i++) {
        if ((*usuarios)[i].idUsuario == idEliminar) {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar != -1) {
        // Mover los elementos restantes para llenar el hueco
        for (int i = indiceEliminar; i < *cantidadUsuarios - 1; i++) {
            (*usuarios)[i] = (*usuarios)[i + 1];
        }

        (*cantidadUsuarios)--;
        *usuarios = (Usuario*)realloc(*usuarios, (*cantidadUsuarios) * sizeof(Usuario));

        printf("Usuario eliminado con éxito.\n");
    } else {
        printf("Usuario no encontrado.\n");
    }
}
