//
// Created by Franco on 22/4/2023.
// Ejercicio - Programacion Bajo Nivel - Untref
// Consigna: Crear una entidad persona con todos los atributos necesarios para definir esta entidad de negocio (a elección).
// Crear funciones que permitan crear la entidad, modificar sus datos, imprimir la información de la entidad.
// Interpretar qué sucede a nivel memoria cuando llamamos a una función y le pasamos el struct.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
persona *crearPersona(char *nombre, char *apellido, short int edad, char *direccion, char *dni) {
    // persona p;
    // -- Nota: Si creamos una estructura persona desde el scope de esta funcion y luego retornamos su dirección de memoria,
    // luego en la funcion main esta variable dejaría de existir entonces este espacio de memoria dejaría de estar reservado,
    // por lo tanto al querer acceder a los atributos de la persona creada desde el mail obtendriamos que son nulos.

    // -- Nota : Para que la creación sea correcta, debemos realizar la reserva de un espacio de memoria con la función malloc(), el cual
    // solo se liberará cuando se lo indiquemos con la función free().
    persona *p = (persona *)malloc(sizeof(persona));
    if (p == NULL) {
        printf( "Error al allocar memoria\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p->nombre, nombre);
    strcpy(p->apellido, apellido);
    p->edad = edad;
    strcpy(p->direccion, direccion);
    strcpy(p->dni, dni);
    return p;
}

// Función para imprimir atributos de una persona
void imprimirPersona(persona *p) {
    // Nota:  podriamos usar los getters para obtener los atributos de la persona
    // pero en este caso preferimos que imprimirPersona sea una funcion independiente de las demás.
    printf("Nombre: %s\n", p->nombre);
    printf("Apellido: %s\n", p->apellido);
    printf("Edad: %hd\n", p->edad);
    printf("Direccion: %s\n", p->direccion);
    printf("DNI: %s\n", p->dni);
}

// -- Setters --
// Función para setear atributo Edad de estructura persona
void setEdad(persona *p, short int edad) {
    p->edad = edad;
}

// Función para setear atributo Direccion de estructura persona
void setDireccion(persona *p, char *direccion) {
    strcpy(p->direccion, direccion);
}

void setNombre(persona *p, char *nombre) {
    strncpy(p->nombre, nombre, sizeof(p->nombre));
}

void setApellido(persona *p, char *apellido) {
    strcpy(p->apellido, apellido);
}

void setDni(persona *p, char *dni) {
    strcpy(p->dni, dni);
}

// -- Getters --
char* getNombre(persona *p) {
    return p->nombre;
}

char* getApellido(persona *p) {
    return p->apellido;
}

short int getEdad(persona *p) {
    return p->edad;
}

char* getDireccion(persona *p) {
    return p->direccion;
}

char* getDni(persona *p) {
    return p->dni;
}

// -- Función para eliminar una persona --
void eliminarPersona(persona *p) {
    // -- En esta función liberamos la memoria reservada al crear a la persona con malloc()
    free(p);
}

float averageBetween3Elements(int dato1, int dato2, int dato3) {
    int largoDeDatos = 3;
    int sum = 0;
    int i;

    sum = dato1 + dato2 + dato3;
    float avg = (float) sum / largoDeDatos;
    return avg;
}

void crearVectorIterable(int *nuevoVector){
    nuevoVector = (int *)malloc(1 * sizeof(int));
}
//
// Nota: Se pretendia agregar uno por uno los elementos a un vector dinamico y luego sacar promedio con
// una funcion average que acepte un int * como parametro sin conocer su largo pero podiendo identificar su final
// identificando el null.
//void agregarElementoAVectorIterable(int *datos)
//void average(int *)

int main(){
    // Creamos una persona
    persona *p = crearPersona("Franco", "Macen", 26, "Calle Falsa 123", "39000000");
    float promedioEdad;

    // -- Imprimimos su información
    imprimirPersona(p);

    // -- Cambiamos su dirección, edad y dni
    setDireccion(p, "Aviador Franco 456");
    setEdad(p, 35);
    setDni(p, "39592443");

    // -- Imprimimos su información nuevamente
    imprimirPersona(p);

    // -- Si por ejemplo quiero obtener un dato específico
    // -- de la persona, puedo usar los getters. Por ejemplo si
    // -- queremos obtener un promedio de las edades.
    promedioEdad = averageBetween3Elements(getEdad(p), 32, 33);
    printf("Promedio de edad: %.2f\n", promedioEdad);

    // -- Eliminamos la persona
    eliminarPersona(p);

    // -- Si quisieramos acceder nuevamente a sus atributos, esto no sería posible ya que la memoria apuntada
    // -- por p ahora fue liberada y el sistema puede usarla para alguna otra operación.
    // -- Si imprimieramos, podríamos ver los datos previamente guardados, basura, o quizas ningun dato. Probar descomentando.
    // imprimirPersona(p);

    return 0;
}
