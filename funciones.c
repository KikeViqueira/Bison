#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

extern FILE *yyin;
extern char *yytext;
extern int yylex_destroy();
void leer_archivo(char *filename);
void terminar_archivo();
void procesar_linea(const char *linea);
void finalizarLexico();
void yyrestart(FILE *new_file);

// void procesarArchivo(const char *nombreArchivo);

void leer_archivo(char *filename) {
    FILE *archivo = fopen(filename, "r");
    if (archivo == NULL) {
        printf(RED"Error al abrir el archivo '%s'\n"RESET, filename);
    } else {
        if (yyin != stdin && yyin != NULL) { //Caso de si tenemos un load dentro de el archivo que estamos leyendo, tenemos que cerrar el archivo que estamos leyendo ya que el nuevo archivo se puede abrir
            fclose(yyin); 
            yyin = NULL;
        }
        yyin = archivo; // Establece el nuevo archivo como entrada para Flex
        printf("Procesando archivo: %s\n", filename);
    }
}

void terminar_archivo() {
    fclose(yyin);     // cierro el archivo
    yyrestart(stdin); // vuelvo a poner stdin
}

void finalizarLexico() {
    yylex_destroy(); 
}

void help(){
    printf("Mostrar ayuda:\n");
    printf(" 1. HELP: Muestra esta ayuda.\n");
    printf(" 2. EXIT: Sale del programa.\n");
    printf(" 3. CLEAR: Limpia el entorno de trabajo excepto constantes y funciones.\n");
    printf(" 4. WORKSPACE: Muestra el entorno de trabajo.\n");
    printf(" 5. LOAD fichero.txt: Carga un archivo con formato [txt].\n");
    printf(" 6. ECHO(ON/OFF): Activa o desactiva el eco del output.\n");
    printf("\t - ON: Activa el eco del output, si no se quiere ver el output con esta opción activada (que viene por defecto) hay que poner al final de la instrucción -> ';'.\n");
    printf("\t - OFF: Desactiva el eco del output.\n");
    printf("\t - NOTA: Da igual que opción esté puesta que el output de los comandos y el valor de las variable o constantes que se pidan siempre se van a ver\n");
}


