#include "../include/array.h"

/* --------------------------------------------------------------------------
 * Implementación de las funciones para el manejo de un arreglo dinámico en C.
 * -------------------------------------------------------------------------- */

// Función para crear un nuevo arreglo dinámico con una capacidad inicial dada.
Array* array_create(int initial_capacity) {
    // Reservamos memoria para la estructura Array.
    Array* array = (Array*)malloc(sizeof(Array));
    if (array == NULL) {
        fprintf(stderr, "> ERROR: No se pudo asignar memoria para el arreglo.\n");
        return NULL; // Si la asignación falla, retornamos NULL.
    }
    // Inicializamos los campos de la estructura
    array->data = (int*)malloc(initial_capacity * sizeof(int));
    if (array->data == NULL) {
        fprintf(stderr, "> ERROR: No se pudo asignar memoria para los datos del arreglo.\n");
        free(array); // Liberamos la memoria previamente asignada.
        return NULL; // Si la asignación falla, retornamos NULL.
    }
    // Inicializamos la capacidad y el tamaño del arreglo.
    array->capacity = initial_capacity;
    array->size = 0;

    // Indicamos que la creación del arreglo fue exitosa.
    printf("> Se creó un arreglo dinámico con capacidad inicial de %d.\n", initial_capacity);
    return array;
}

// Función para agregar un elemento al final del arreglo dinámico.
void array_add_element(Array* array, int value) {
    if (array == NULL) {
        fprintf(stderr, "> ERROR: Arreglo no válido.\n");
        return;
    }
    // Verificamos si el arreglo está lleno y necesitamos redimensionarlo.
    if (array->size >= array->capacity) {
        int new_capacity = array->capacity * 2; // Duplicamos la capacidad del arreglo.
        int* new_data = (int*)realloc(array->data, new_capacity * sizeof(int));

        // Verificamos si la reasignación fue exitosa.
        if (new_data == NULL) {
            fprintf(stderr, "> ERROR: No se pudo redimensionar el arreglo.\n");
            return;
        }
        // Actualizamos el puntero y la capacidad del arreglo.
        array->data = new_data;
        array->capacity = new_capacity;
        printf("> El arreglo fue redimensionado. Nueva capacidad: %d.\n", new_capacity);
    }
    // Agregamos el nuevo elemento al final del arreglo.
    array->data[array->size] = value;
    array->size++;
    printf("> Se agregó el elemento '%d' al arreglo.\n", value);
}

// Función para eliminar un elemento en una posición específica del arreglo dinámico.
void array_delete_element(Array* array, int index) {
    if (array == NULL) {
        fprintf(stderr, "> ERROR: Arreglo no válido.\n");
        return;
    }
    // Verificamos si el índice está dentro de los límites del arreglo.
    if (index < 0 || index >= array->size) {
        fprintf(stderr, "> ERROR: Índice fuera de rango.\n");
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
    printf("> Se eliminó el elemento '%d' (índice %d).\n", deleted_value, index);
}

// Función para obtener un elemento en una posición específica del arreglo dinámico.
int array_get_element(Array* array, int index) {
    if (array == NULL) {
        fprintf(stderr, "> ERROR: Arreglo no válido.\n");
        return -1; // Retornamos un índice inválido para indicar error.
    }
    // Verificamos si el índice está dentro de los límites del arreglo.
    if (index < 0 || index >= array->size) {
        fprintf(stderr, "> ERROR: Índice fuera de rango.\n");
        return -1; // Retornamos un índice inválido para indicar error.
    }
    // Retornamos el elemento en la posición especificada.
    return array->data[index];
}

// Función para mostrar todos los elementos del arreglo dinámico.
void array_print(Array* array) {
    if (array == NULL) {
        fprintf(stderr, "> ERROR: Arreglo no válido.\n");
        return;
    }
    printf("> Elementos del arreglo dinámico (tamaño actual: %d): [", array->size);

    // Iteramos sobre cada elemento del arreglo y lo mostramos.
    for (int i = 0; i < array->size; i++) {
        printf("%d", array->data[i]);
        if (i < array->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Función para liberar la memoria utilizada por el arreglo dinámico.
void array_free(Array* array) {
    if (array == NULL) {
        return; // Si el arreglo es NULL, no hay nada que liberar.
    }
    free(array->data); // Primero, liberamos la memoria de los datos del arreglo.
    free(array); // Luego, liberamos la memoria de la estructura del arreglo.
    printf("> Se liberó la memoria del arreglo dinámico.\n");
}
