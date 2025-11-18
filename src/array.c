#include "../include/array.h"

/* --------------------------------------------------------------------------
 * Implementación de las funciones para el manejo de un arreglo dinámico en C.
 * -------------------------------------------------------------------------- */

// Función para crear un nuevo arreglo dinámico con una capacidad inicial dada.
Array* array_create(int initial_capacity) {
    // Reservamos memoria para la estructura Array.
    Array* array = (Array*)malloc(sizeof(Array));
    if (array == NULL) {
        fprintf(stderr, "ERROR: No se pudo asignar memoria para el arreglo.\n");
        return NULL; // Si la asignación falla, retornamos NULL.
    }
    // Inicializamos los campos de la estructura
    array->data = (int*)malloc(initial_capacity * sizeof(int));
    if (array->data == NULL) {
        fprintf(stderr, "ERROR: No se pudo asignar memoria para los datos del arreglo.\n");
        free(array); // Liberamos la memoria previamente asignada.
        return NULL; // Si la asignación falla, retornamos NULL.
    }
    // Inicializamos la capacidad y el tamaño del arreglo.
    array->capacity = initial_capacity;
    array->size = 0;

    // Indicamos que la creación del arreglo fue exitosa.
    printf("Se creó un arreglo dinámico con capacidad inicial de %d.\n", initial_capacity);
    return array;
}

// Función para agregar un elemento al final del arreglo dinámico.
void array_add_element(Array* array, int value) {
    if (array == NULL) {
        fprintf(stderr, "ERROR: Arreglo no válido.\n");
        return;
    }
    // Verificamos si el arreglo está lleno y necesitamos redimensionarlo.
    if (array->size >= array->capacity) {
        int new_capacity = array->capacity * 2; // Duplicamos la capacidad del arreglo.
        int* new_data = (int*)realloc(array->data, new_capacity * sizeof(int));

        // Verificamos si la reasignación fue exitosa.
        if (new_data == NULL) {
            fprintf(stderr, "ERROR: No se pudo redimensionar el arreglo.\n");
            return;
        }

        // Actualizamos el puntero y la capacidad del arreglo.
        array->data = new_data;
        array->capacity = new_capacity;
        printf("El arreglo fue redimensionado. Nueva capacidad: %d.\n", new_capacity);
    }
    // Agregamos el nuevo elemento al final del arreglo.
    array->data[array->size] = value;
    array->size++;
    printf("Se agregó el elemento %d al arreglo. Tamaño actual: %d.\n", value, array->size);
}

// Función para eliminar un elemento en una posición específica del arreglo dinámico.
void array_delete_element(Array* array, int index) {
    if (array == NULL) {
        fprintf(stderr, "ERROR: Arreglo no válido.\n");
        return;
    }
    // Verificamos si el índice está dentro de los límites del arreglo.
    if (index < 0 || index >= array->size) {
        fprintf(stderr, "ERROR: Índice fuera de rango.\n");
        return;
    }
    // Guardamos el valor que será eliminado para mostrarlo después.
    int deleted_value = array->data[index];

    // Desplazamos los elementos a la izquierda para llenar el espacio del elemento eliminado.
    for (int i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }

    // Decrementamos el tamaño del arreglo.
    array->size--;
    printf("Se eliminó el elemento %d en el índice %d.\n", deleted_value, index);
}

//
