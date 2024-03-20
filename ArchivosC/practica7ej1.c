#include <stdio.h>
#include <stdlib.h>
//Declaracion del nodo que nos va a servir para guardar datos y enlazarlos
struct nodo{
int dato;
struct nodo *siguiente;
};
//estructura de lista
struct lista{
struct nodo *head;
};
//Operaciones basicas
int crearLista(struct lista *);
int insertar(struct lista *, int);
int borrar(struct lista *,int);
int buscar(struct lista *, int);
void verLista(struct lista *);
int esVacio(struct lista *);
int main(){
struct lista miLista;
crearLista(&miLista);
esVacio(&miLista);
insertar(&miLista,5);
insertar(&miLista,3);
insertar(&miLista,1);
verLista(&miLista);
buscar(&miLista,1);
borrar(&miLista,1);
verLista(&miLista);
borrar(&miLista,1);
borrar(&miLista,5);
verLista(&miLista);
system("PAUSE");
return 0;
}
int crearLista(struct lista *nuevaLista){
nuevaLista->head = NULL; //Inicializamos la Lista
return 0;
}
int insertar(struct lista *insertarLista, int dato){
//Creamos un nuevo nodo de la estructura nodo
struct nodo *nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
if(nuevoNodo==NULL){
printf("No se pudo asignar la memoria al elemnto\n");
return -1;
}
//si se creo correctamente
//Pasamos el nuevo valor que se va a ingresar a la lista
nuevoNodo->dato = dato; // le damos el dato al nuevo nodo
nuevoNodo->siguiente = insertarLista->head; // El siguiente del nuevo nodo apunta
al nodo que estaba en la cabeza
insertarLista->head = nuevoNodo; // Ahora el nuevo nodo se convierte en la nueva
cabeza de la lista
return 0;
}
int borrar(struct lista *borrarLista,int dato){
//verificamos si lista esta vacia
if(borrarLista->head==NULL){
printf("Error la lista esta vacia\n");
return -1;
}
//Si no esta vacia creamos un nuevo nodo auxiliar para poder eliminar
struct nodo *nodoEliminar = borrarLista->head;//Se crea un nuevo nodo poniendolo en el
elemento conde apunta head
struct nodo *nodoPrevio =NULL;
//buscamos el elemneto
while(nodoEliminar != NULL && nodoEliminar->dato != dato){
nodoPrevio = nodoEliminar;
nodoEliminar = nodoEliminar->siguiente;
}
if(nodoEliminar==NULL){
printf("El elemento no esta en la lista a eliminar\n");
return -1;
}
//Si es el Primer elemento a aliminar
if(nodoEliminar == borrarLista->head){
borrarLista->head = nodoEliminar->siguiente;
}else{
nodoPrevio->siguiente=nodoEliminar->siguiente;
}
free(nodoEliminar);//Se elimina el nodo
return 0;
}
int buscar(struct lista *miLista,int dato){
struct nodo *nodoAuxiliar= miLista->head;//creamos un nodo auxiliar para obtener los
elementos de la cola empezando en el frente
while(nodoAuxiliar!=NULL){
if(nodoAuxiliar->dato == dato){
printf("Dato encontrado\n");
return nodoAuxiliar->dato;
}
nodoAuxiliar=nodoAuxiliar->siguiente;
}
printf("Dato no encontrado\n");
return -1;
}
void verLista(struct lista *miLista){
struct nodo *nodoAuxiliar=miLista->head;//creamos un nodo auxiliar
printf("Datos en la Lista\n");
while(nodoAuxiliar!=NULL){
printf("%d",nodoAuxiliar->dato);//va a ir a la estructura de la pila en su variable dato
y la imprime
printf("\n");
nodoAuxiliar = nodoAuxiliar->siguiente;//va ir al campo sighuiente es decir al nodo
que esta siguiente del actual
//Y se pa a posicionar con su direccion de memoria en dicho nodo.
}
printf("\n");
}
int esVacio(struct lista *miLista){
if(miLista->head==NULL){//Verificamois si es nulo
printf("Esta Vacio\n");
return -1;
}else{
return 0;
}
}