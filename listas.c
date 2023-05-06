//
// Created by Franco on 6/5/2023.
//

#include "listas.h"

// -- Función para crear e inicializar la lista
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    return list;
}

// -- Función para agregar un elemento al final de la lista
void addElement(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // -- Verificamos si previamente la lista estaba vacía o si hay que recorrerla hasta el final y luego agregar el nodo Nuevo
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    list->size++;
}

// -- Obtener el largo de la lista
int getListLength(LinkedList* list) {
    return list->size;
}

// -- Obtener un elemento N de la lista
Node* getElement(LinkedList* list, int n) {

    // -- Verificamos parametro
    if (n >= list->size) {
        return NULL;
    }

    // -- Usando un puntero auxiliar curr (current) recorremos la lista hasta encontrar el elemento deseado
    Node* curr = list->head;
    for (int i = 0; i < n; i++) {
        curr = curr->next;
    }

    return curr;
}

// -- Funcion para eliminar un elemento N de la lista
void deleteElement(LinkedList* list, int n) {
    if (n >= list->size) {
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

    list->size--;
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

// función main para probar la lista
int ejercicioListas() {
    LinkedList* list = createLinkedList();

    addElement(list, 15);
    addElement(list, 23);
    addElement(list, 31);

    printList(list);
    printf("Largo de la lista: %d\n", getListLength(list));

    printf("Elemento 1: %d\n", getElement(list, 15)->data);

    deleteElement(list, 15);

    printList(list);

    printf("Largo de la lista: %d\n", getListLength(list));

    return 0;
}
