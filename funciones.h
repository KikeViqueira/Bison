#ifndef BISON_FUNCIONES_H
#define BISON_FUNCIONES_H

//Función para leer un archivo y establecerlo como entrada para Flex
void leer_archivo(char *filename);
//Función para terminar el archivo que se está leyendo y restaurar la entrada estándar
void terminar_archivo();
// Función para liberar correctamente los rescursos usados por Flex
void finalizarLexico();
// Función para enseñar por terminal la ayuda, y dar una comprensión de como se usa el programa
void help();

#endif //BISON_FUNCIONES_H
