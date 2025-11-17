#pragma once
#include <stdlib.h>
#include <stdio.h>

/* --------------------------------------------------------------
 * Header file para la implementación de un arreglo dinámico en C.
 * -------------------------------------------------------------- */

// Definimos la estructura del arreglo dinámico para poder manejar su capacidad y tamaño.
typedef struct {
    int *data; // Puntero a los datos del arreglo
    int capacity; // Capacidad total del arreglo
    int size; // Número actual de elementos en el arreglo
} Array;

// Función para crear un nuevo arreglo dinámico con una capacidad inicial dada.
Array* array_create(int initial_capacity);

// Función para agregar un elemento al final del arreglo dinámico.
void array_add_element(Array *array, int value);

// Función para eliminar un elemento en una posición específica del arreglo dinámico.
void array_delete_element(Array *array, int index);

// Función para obtener un elemento en una posición específica del arreglo dinámico.
int array_get_element(Array *array, int index);

// Función para mostrar todos los elementos del arreglo dinámico.
void array_print(Array *array);

// Función para liberar la memoria utilizada por el arreglo dinámico.
void array_free(Array *array);
