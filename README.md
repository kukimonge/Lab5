# Lab5

Este repositorio contiene la implementación de un **arreglo dinámico** desarrollado en C como parte del Laboratorio 5 del curso **IE-0117 Programación Bajo Plataformas Abiertas**.

## Estructura del Proyecto

```
Lab5/
├── include/
│   └── array.h          # Interfaz del arreglo dinámico (declaraciones y constantes)
├── src/
│   ├── array.c          # Implementación de las funciones del arreglo dinámico
│   └── main.c           # Programa principal de demostración
├── bin/                 # Directorio para el ejecutable (generado automáticamente)
├── obj/                 # Directorio para archivos objeto (generado automáticamente)
├── Makefile             # Automatización de compilación y ejecución
└── README.md            # Este archivo
```

## Descripción

El proyecto implementa una **estructura de datos de arreglo dinámico** con capacidad de redimensionamiento automático. La implementación incluye operaciones fundamentales para el manejo de arreglos, gestión eficiente de memoria y validación exhaustiva con Valgrind.

### Características Técnicas

- Redimensionamiento automático cuando se alcanza la capacidad
- Validación exhaustiva de entrada y manejo de errores
- Gestión de memoria sin fugas (validado con Valgrind)

## Requisitos del Sistema

- **Compilador**: GCC (GNU Compiler Collection)
- **Make**: Para automatización de compilación
- **Valgrind**: Para verificación de memory leaks (opcional)
- **Sistema Operativo**: Linux, macOS, o WSL en Windows

## Pasos para Compilar

### Compilación estándar

Para compilar el proyecto, ejecuta:

```bash
make
```

Este comando realiza las siguientes acciones:
1. Crea los directorios `bin/` y `obj/` si no existen
2. Compila los archivos fuente (`.c`) a archivos objeto (`.o`)
3. Enlaza los archivos objeto para generar el ejecutable `bin/main`

### Limpiar archivos generados

Para eliminar todos los archivos compilados:

```bash
make clean
```

### Recompilar desde cero

Para limpiar y compilar en un solo paso:

```bash
make clean && make
```

## Pasos para Ejecutar

### Ejecución del programa

Una vez compilado, puedes ejecutar el programa de dos formas:

**Opción 1: Ejecutar directamente el binario**
```bash
./bin/main
```

**Opción 2: Usar el Makefile**
```bash
make run
```

### Verificación de memory leaks con Valgrind

Para verificar que no hay fugas de memoria:

```bash
make valgrind
```

## Comandos Disponibles

| Comando | Descripción |
|---------|-------------|
| `make` | Compila el proyecto |
| `make run` | Compila y ejecuta el programa |
| `make clean` | Elimina archivos compilados |
| `make valgrind` | Ejecuta con Valgrind para detectar memory leaks |
| `make help` | Muestra ayuda de comandos disponibles |
