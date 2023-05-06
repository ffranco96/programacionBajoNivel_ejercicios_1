//
// Created by Franco on 6/5/2023.
//



#ifndef PROGRAMACIONBAJONIVEL_EJERCICIOS_1_LISTAS_H \
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// -- Estructura nodo
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// -- Estructura lista enlazada
typedef struct LinkedList {
    int size;
    Node* head;
} LinkedList;

LinkedList* createLinkedList();
void addElement(LinkedList* list, int data) ;
int getListLength(LinkedList* list);
Node* getElement(LinkedList* list, int n);
void deleteElement(LinkedList* list, int n);
void printList(LinkedList* list);
int ejercicioListas();
#define PROGRAMACIONBAJONIVEL_EJERCICIOS_1_LISTAS_H

#endif //PROGRAMACIONBAJONIVEL_EJERCICIOS_1_LISTAS_H
