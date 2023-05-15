//
// Created by Franco on 6/5/2023.
//

#include "listas.h"

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
//Node* getElement(LinkedList* list, int n) {
//    //@todo POr aca hay un segmentation fault
//    // -- Verificamos parametro
//    if (n >= list->length) {
//        return NULL;
//    }
//
//    // -- Usando un puntero auxiliar curr (current) recorremos la lista hasta encontrar el elemento deseado
//    Node* curr = list->head;
//    for (int i = 0; i < n; i++) {
//        curr = curr->next;
//    }
//
//    return curr;
//}

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

    // -- Specific case: if list is empty, we just add new node as list header
    if (list->head == NULL) {
        list->head = newNode;
        list->length++;
        return;
    }

    // -- General case: we go through the list to find the right position for the new node
    prev = NULL;
    curr = list->head;
    while (curr != NULL && curr->data < data) {
        prev = curr;
        curr = curr->next;
    }

    // -- Insert the new node in the right position
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
/*
    addElement(list, 23);
    addElement(list, 15);
    addElement(list, 31);
    addElement(list, 3);
*/
    printList(list);
    printf("Largo de la lista: %d\n", getListLength(list));

//    printf("Elemento 1: %d\n", getElement(list, 15)->data);
/*
    deleteElement(list, 15);

    printList(list);

    printf("Largo de la lista: %d\n", getListLength(list));*/

    // -- Part2 - Now we are going to add sorted elements
    addSortedElement(sortedList, 23);
    addSortedElement(sortedList, 15);
    addSortedElement(sortedList, 31);
    addSortedElement(sortedList, 3);
    printList(sortedList);

    return 0;
}
