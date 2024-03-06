#include <stdio.h>

#define MAX_SIZE 10

// Definición de la estructura de la cola
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Función para inicializar la cola
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Función para comprobar si la cola está vacía
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Función para comprobar si la cola está llena
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Función para añadir un elemento a la cola (enqueue)
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Error: la cola está llena, no se puede realizar enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->items[++queue->rear] = value;
        printf("Elemento %d añadido a la cola.\n", value);
    }
}

// Función para encontrar el elemento máximo en la cola
int findMax(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: la cola está vacía, no hay máximo.\n");
        return -1; // Valor indicando error
    } else {
        int max = queue->items[queue->front];
        for (int i = queue->front + 1; i <= queue->rear; i++) {
            if (queue->items[i] > max) {
                max = queue->items[i];
            }
        }
        return max;
    }
}

// Función para invertir la mitad de los elementos de la cola
void invertHalf(struct Queue *queue) {
    if (isEmpty(queue) || (queue->rear - queue->front + 1) < 2) {
        printf("No hay suficientes elementos para invertir la mitad.\n");
    } else {
        int start = queue->front;
        int end = queue->front + (queue->rear - queue->front) / 2;

        while (start < end) {
            // Intercambiar elementos para invertir la mitad
            int temp = queue->items[start];
            queue->items[start] = queue->items[end];
            queue->items[end] = temp;

            start++;
            end--;
        }

        printf("Mitad de los elementos invertidos.\n");
    }
}

// Función para mostrar la cola
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
    } else {
        printf("Contenido de la cola:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    // Ingreso de 10 elementos por parte del usuario
    printf("Ingrese 10 elementos en la cola:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        int element;
        printf("Elemento %d: ", i + 1);
        scanf("%d", &element);
        enqueue(&queue, element);
    }

    // Encontrar y mostrar el elemento máximo
    int maxElement = findMax(&queue);
    if (maxElement != -1) {
        printf("Elemento máximo en la cola: %d\n", maxElement);
    }

    // Invertir la mitad de los elementos y mostrar la cola resultante
    invertHalf(&queue);
    display(&queue);

    return 0;
}
