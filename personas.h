//
// Created by Franco on 6/5/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PROGRAMACIONBAJONIVEL_EJERCICIOS_1_PERSONAS_H
#define PROGRAMACIONBAJONIVEL_EJERCICIOS_1_PERSONAS_H

#define TRUE 1
#define FALSE 0

typedef struct{
    char nombre[20];
    char apellido[20];
    short int edad;
    char direccion[100];
    char dni[8 + 1];
}persona;

// Función para crear una estructura persona
persona *crearPersona(char *nombre, char *apellido, short int edad, char *direccion, char *dni);

// Función para imprimir atributos de una persona
void imprimirPersona(persona *p);

// -- Setters --
// Función para setear atributo Edad de estructura persona
void setEdad(persona *p, short int edad);

// Función para setear atributo Direccion de estructura persona
void setDireccion(persona *p, char *direccion);

void setNombre(persona *p, char *nombre);

void setApellido(persona *p, char *apellido);

void setDni(persona *p, char *dni);

// -- Getters --
char* getNombre(persona *p);

char* getApellido(persona *p);

short int getEdad(persona *p);

char* getDireccion(persona *p);

char* getDni(persona *p);

// -- Función para eliminar una persona --
void eliminarPersona(persona *p);

// -- Otros --
float averageBetween3Elements(int dato1, int dato2, int dato3);

void crearVectorIterable(int *nuevoVector);

// -- Funcion principal del ejercicio de personas --
void ejercicioPersonas();
#endif //PROGRAMACIONBAJONIVEL_EJERCICIOS_1_PERSONAS_H
