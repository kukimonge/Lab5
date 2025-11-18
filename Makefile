# ------------------------------------------------------
# Makefile para compilar el proyecto de arreglo dinámico.
# ------------------------------------------------------

# Compilador y flags de compilación
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -g

# Directorios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Archivos
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/array.c
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
HEADERS = $(INC_DIR)/array.h
TARGET = $(BIN_DIR)/main

# Regla de compilación por defecto
all: $(TARGET)
	@echo ""
	@echo "--- COMPILACIÓN COMPLETADA ---"
	@echo ""
	@echo "Para ejecutar el programa, usa 'make run'."
	@echo "Para ejecutar con valgrind, usa 'make valgrind'."
	@echo "Para limpiar los archivos generados, usa 'make clean'."
	@echo ""

# Regla para crear el ejecutable final
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	@echo "> Enlazando archivos objeto..."
	@$(CC) $(CFLAGS) -o $@ $^

# Compilar archivos .c a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo "> Compilando $<..."
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Crear directorio bin si no existe
$(BIN_DIR):
	@echo "> Creando directorio bin..."
	@mkdir -p $(BIN_DIR)

# Crear directorio obj si no existe
$(OBJ_DIR):
	@echo "> Creando directorio obj..."
	@mkdir -p $(OBJ_DIR)

# Regla para compilar y ejecutar el programa
run: $(TARGET)
	@echo ""
	@echo "--- EJECUTANDO PROGRAMA ---"
	@echo ""
	@./$(TARGET)

# Regla para ejecutar el programa con Valgrind (detección de memory leaks)
valgrind: $(TARGET)
	@echo ""
	@echo "--- EJECUTANDO PROGRAMA CON VALGRIND ---"
	@echo ""
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Regla para limpiar los archivos generados
clean:
	@echo "> Limpiando archivos generados..."
	@echo ""
	@rm -rf $(BIN_DIR) $(OBJ_DIR)
	@echo "--- LIMPIEZA COMPLETADA ---"
	@echo ""

# Regla para mostrar ayuda
help:
	@echo ""
	@echo "Comandos disponibles:"
	@echo "  make              - Compilar el proyecto"
	@echo "  make run          - Compilar y ejecutar el programa"
	@echo "  make clean        - Limpiar archivos compilados"
	@echo "  make valgrind     - Ejecutar con Valgrind (memory leak check)"
	@echo "  make help         - Mostrar esta ayuda"
	@echo ""

# Marcar las reglas que no corresponden a archivos
.PHONY: all run valgrind clean help
