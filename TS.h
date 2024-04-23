#ifndef TS_H
#define TS_H

#define VARIABLE 0
#define FUNCION 1
#define CONSTANTE 2

#include "abb.h"
// Función para inicializar la tabla y cargar las palabras reservadas función
void initTS();

// Función para buscar una variable dentro de la tabla de símbolos por su lexema, mete su numero correspondiente en la estructura
//En caso de buscar de forma correcta la variable (no coincidir con una función o constante) se le asigna el nuevo contenido a la variable y se modifica el nodo en la tabla de simbolos
//EN caso de que la variable no exista en la tabla de simbolos, se inserta en la tabla de simbolos, siempre y cuando no sea una función o constante
//Devuelve 1 si se ha encontrado la variable y se ha modificado su contenido o se ha insertado con su contenido inicial, 0 si no se ha encontrado la variable o esta coincide con una función o constante
int buscarVariable(char *lexema, double nuevoContenido);

// Función para insertar un lexema en la tabla de símbolos
void insertarLexema(char *lexema_a_insertar,TIPOELEMENTOABB *nodo);

//Funcion para devolver a bison el contenido de una variable o constante si esta está en la tabla de símbolos
double recuperarContenidoVarCons(char *lexema);

//Funcion para devolver a bison el puntero de una función si esta está en la tabla de símbolos
double (*recuperarContenidoFuncion(char *lexema))(void);

//Función para imprimir el contenido de la tabla de símbolos
void imprimirTablaSimbolos();

//Función para liberar la memoria usada por la tabla de símbolos
void liberarTS();

//Funcion para darle el valor de la bandera a Bison
int getValor();

//Funcion para poner la bandera otra vez en True
void setValor(int valor);

//Función la cual hace el comportamiento de el comando CLEAR en nuestra calculadora
void clear();

//Función para saber que tipo de identificador se ha leído en el flex y q asi este le pueda devolver la informacion correcta al bison
int tipoIdentificador(char *lexema);

#endif