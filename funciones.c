#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin; // Definición externa, ya que yyin se define en
extern int yylex_destroy();

// void procesarArchivo(const char *nombreArchivo);

void leer_archivo(char *filename) {
    FILE *archivo = fopen(filename, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo '%s'\n", filename);
    } else {
        if (yyin) {
            fclose(yyin); // Cierra el archivo actual si está abierto
        }
        yyin = archivo;  // Establece el nuevo archivo como entrada para Flex
        yyrestart(yyin); // Reinicia el scanner para el nuevo archivo
        printf("Procesando archivo: %s\n", filename);

        while (!feof(yyin)) {
            char buffer[1024];
            if (fgets(buffer, 1024, yyin) != NULL) {
                procesar_linea(buffer);
            }
        }
        terminar_archivo();
    }
}

void procesar_linea(const char *linea) {
    if (strncmp(linea, "LOAD ", 5) == 0) { // Comprueba si la línea comienza con "LOAD "
        char new_filename[256];
        if (sscanf(linea, "LOAD %s", new_filename) == 1) { // Obtiene el nombre del archivo
            leer_archivo(new_filename);
        }
    }
}

void terminar_archivo() {
    if (yyin) {
        fclose(yyin); // Cierra el archivo
        yyin = NULL;
    }
    yyrestart(stdin); // Vuelve a stdin como entrada de Flex
}

// Procedimientos de liberación de memoria para la finalización del análisis léxico
void finalizarLexico() {
    yylex_destroy(); // Libero  la memria de yylex
}
