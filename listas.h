//
// Created by Franco on 6/5/2023.
//



#ifndef PROGRAMACIONBAJONIVEL_EJERCICIOS_1_LISTAS_H
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
    int length;
    Node* head;
} LinkedList;

/*
 * @brief
 * Crea e inicializa una estructura lista enlazada de tipo LinkedList que contiene los elementos:
 * #length: largo de la lista enlazada
 * #head : puntero de tipo Node * que apunta al primer elemento de la lista, si existe, de lo contrario apunta a NULL.
 * @author Franco Macen
 * */

/*
 * @todo finish documentation
 * */
LinkedList* createLinkedList();
void addElement(LinkedList* list, int data) ;
int getListLength(LinkedList* list);
void getElementByPosition(LinkedList* list, int n, Node **obtainedNode);
void deleteElement(LinkedList* list, int n);
void printList(LinkedList* list);

// Función para agregar un elemento a la lista de forma ordenada
void addSortedElement(LinkedList* list, int data);

// -- TP listas --
int ejercicioListas();
#define PROGRAMACIONBAJONIVEL_EJERCICIOS_1_LISTAS_H

#endif //PROGRAMACIONBAJONIVEL_EJERCICIOS_1_LISTAS_H
