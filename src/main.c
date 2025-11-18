#include <stdio.h>
#include "../include/array.h"

/* -----------------------------------------------------------------------
 * Programa principal para demostrar la funcionalidad del arreglo dinámico.
 * ----------------------------------------------------------------------- */

 // Función principal del programa.
int main(void) {
    // Creamos un nuevo arreglo dinámico con una capacidad inicial de 3.
    printf("Creando un arreglo con capacidad inicial para 3 elementos...\n");
    Array* arregloPrueba = array_create(3);
    array_print(arregloPrueba);
    printf("\n");

    // Agregamos algunos elementos al arreglo.
    printf("Agregando elementos al arreglo...\n");
    array_add_element(arregloPrueba, 15);
    array_add_element(arregloPrueba, 22);
    array_add_element(arregloPrueba, 34);
    array_print(arregloPrueba);
    printf("\n");

    // Agregamos más elementos para forzar la redimensión del arreglo.
    printf("Agregando más elementos para forzar la redimensión...\n");
    array_add_element(arregloPrueba, 6);
    array_print(arregloPrueba);
    printf("\n");

    array_add_element(arregloPrueba, 19);
    array_print(arregloPrueba);
    printf("\n");

    // Mostramos un elemento específico del arreglo, por ejemplo, el índice 2.
    int elementoPrueba = array_get_element(arregloPrueba, 2);
    printf("El elemento en el índice 2 es: %d\n\n", elementoPrueba);

    // Eliminamos un elemento en una posición específica, por ejemplo, el índice 1.
    printf("Eliminando el elemento en el índice 1...\n");
    array_delete_element(arregloPrueba, 1);
    array_print(arregloPrueba);
    printf("\n");

    // Intentamos obtener un elemento en un índice inválido para verificar el manejo de errores.
    printf("Intentando obtener un elemento con un índice inválido (10)...\n");
    elementoPrueba = array_get_element(arregloPrueba, 10);
    printf("\n");

    // Intentamos eliminar un elemento en un índice inválido para verificar el manejo de errores.
    printf("Intentando eliminar un elemento con un índice inválido (10)...\n");
    array_delete_element(arregloPrueba, 10);
    printf("\n");

    // Liberamos la memoria utilizada por el arreglo dinámico.
    printf("Liberando la memoria del arreglo dinámico...\n");
    array_free(arregloPrueba);
    printf("Memoria liberada. Programa finalizado.\n");
    return 0;
}
