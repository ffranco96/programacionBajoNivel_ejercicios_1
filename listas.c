//
// Created by Franco on 6/5/2023.
//

#include "listas.h"
//@todo Cambiar el retorno de todas las funciones para poder manejar sus errores

// -- Función para crear e inicializar la lista
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->length = 0;
    list->head = NULL;
    return list;
}

// -- Función para agregar un elemento al final de la lista
void addElement(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // -- Verificamos si previamente la lista estaba vacía o si hay que recorrerla hasta el final y luego agregar el nodo Nuevo
    // -- En este caso se agrega como al final, como si fuera una cola o lista FIFO.
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    list->length++;
}

// -- Obtener el largo de la lista
int getListLength(LinkedList* list) {
    return list->length;
}

// -- Obtener un elemento N de la lista
void getElementByPosition(LinkedList* list, int n, Node **obtainedNode) {
    Node* curr = NULL;
    // -- Verificamos parametro
    if (n >= list->length) {
        *obtainedNode = curr;
        return;
    }

    // -- Usando un puntero auxiliar curr (current) recorremos la lista hasta encontrar el elemento deseado
    curr = list->head;
    for (int i = 0; i < n; i++) {
        curr = curr->next;
    }

    *obtainedNode = curr;
    return;
}

// -- Funcion para eliminar un elemento N de la lista, siendo n == 0 el primer elemento de la lista
void deleteElement(LinkedList* list, int n) {
    if (n >= list->length) {
        return;
    }

    Node* curr = list->head;
    if (n == 0) {
        list->head = curr->next;
        free(curr);
    } else {
        Node* prev = NULL;
        for (int i = 0; i < n; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
    }

    list->length--;
}

// función para imprimir la lista
void printList(LinkedList* list) {
    Node* curr = list->head;
    printf("Lista: [");
    while (curr != NULL) {
        printf("%d", curr->data);
        curr = curr->next;
        if (curr != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void addSortedElement(LinkedList* list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *prev, *curr;

    newNode->data = data;
    newNode->next = NULL;

    // -- Con lista vacia : simplemente se agrega el nuevo nodo como head de la lista.
    if (list->head == NULL) {
        printf(" Debugger: La lista estaba vacia\n");
        list->head = newNode;
        list->length++;
        return;
    }

    // -- Con lista conteniendo al menos 1 elemento: recorremos la lista para encontrar la posicion correcta para el nuevo nodo
    prev = NULL;
    curr = list->head;
    while (curr != NULL && curr->data < data) {
        prev = curr;
        curr = curr->next;
    }

    // -- Insertamos el nuevo nodo en la posicion correspondiente.
    // -- Se contempla el caso en que se debe insertar un nodo delante del primer elemento.
    if (prev == NULL) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        newNode->next = curr;
        prev->next = newNode;
    }
    list->length++;
}

int ejercicioListas() {
    LinkedList *list = createLinkedList();
    LinkedList *sortedList = createLinkedList();
    Node *auxNode = NULL;
    addElement(list, 23);
    addElement(list, 15);
    addElement(list, 31);
    addElement(list, 3);

    printList(list);
    printf("Largo de la lista: %d\n", getListLength(list));

    getElementByPosition(list, 1, &auxNode);
    if(auxNode != NULL)
        printf("Elemento 1: %d\n", auxNode->data);

    deleteElement(list, 1);

    printList(list);

    printf("Largo de la lista: %d\n", getListLength(list));

    // -- Part2 - Now we are going to add sorted elements
    addSortedElement(sortedList, 23);
    addSortedElement(sortedList, 42);
    addSortedElement(sortedList, 42);
    addSortedElement(sortedList, 15);
    addSortedElement(sortedList, 31);
    addSortedElement(sortedList, 3);
    printList(sortedList);

    return 0;
}
