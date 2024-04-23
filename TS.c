#include "TS.h"
#include "abb.h"
#include <malloc.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265358979323846 // Definimos la constante pi que no se podra modificar su valor
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

TABB arbol;

int devolver = 1; // Bandera para saber si una variable o función se encuentra en la tabla de simbolos y devolver su valor

int getValor() {
    // Funcion para darle el valor de la bandera a Bison
    return devolver;
}

void setValor(int valor) {
    // Funcion para poner la bandera otra vez en True
    devolver = valor;
}

void initTS() {
    // Creamos la estructura base del árbol
    crearAbb(&arbol);

    token funciones[] = {
        {"sin", 1, {.fnctptr = sin}},
        {"cos", 1, {.fnctptr = cos}},
        {"atan", 1, {.fnctptr = atan}},
        {"ln", 1, {.fnctptr = log}},
        {"exp", 1, {.fnctptr = exp}},
        {"sqrt", 1, {.fnctptr = sqrt}},
        // Tenemos que meter a mayores la constante pi
        {"pi", 2, {.var = PI}}};

    int tamanho = sizeof(funciones) / sizeof(token);

    // Insertamos en el árbol las palabras reservadas, cada una en un nodo distinto del árbol
    for (int i = 0; i < tamanho; i++) {
        char *funcion = (char *)malloc(strlen(funciones[i].lexema) + 1);
        strcpy(funcion, funciones[i].lexema);
        funciones[i].lexema = funcion;
        insertarElementoAbb(&arbol, funciones[i]);
    }

    // Imprimimos el árbol para ver si se ha creado de manera correcta
    imprimirTablaSimbolos();
}

int buscarVariable(char *lexema, double nuevoContenido) {
    // Hacemos una copia del nodo, así aunque se libere la memoria del token en otra parte del código, en el árbol seguiremos con su información
    TIPOELEMENTOABB nodoAux;
    nodoAux.lexema = NULL;

    // Tenemos que buscar el nodo con el identificador o clave lexema, si no está se llamará a insertarLexema()
    buscarNodoAbb(arbol, lexema, &nodoAux);

    if (nodoAux.lexema == NULL) {
        /*Si se entra aqui es porque la función buscarnodo no ha encontrado ningún nodo cuya clave coincida con el lexema
         que se ha pasado como clave, en el caso de no entrar en el if ya hemos encontrado el nodo*/
        nodoAux.type = 0; // Se trata de una variable por lo que su respectivo campo vale 0
        nodoAux.tipo.var = nuevoContenido;
        insertarLexema(lexema, &nodoAux);
    } else if (nodoAux.type == 0) {
        // Si la variable no tiene el nombre de una función ni el de una constante, se puede modificar su valor
        nodoAux.tipo.var = nuevoContenido;
        modificarElementoAbb(arbol, nodoAux); // Modificamos el valor del token
    } else if (nodoAux.type == 2 || nodoAux.type == 1) {
        printf("No puedes asignarle un valor a una constante/funcion");
        return 0;
    }
    return 1;
}

void insertarLexema(char *lexema_a_insertar, TIPOELEMENTOABB *nodo) {
    // tenemos que hacer una copia del lexema cuando lo metamos en la TS, porque si no cuando el sintáctico hago un free del token este se borrará también de la tabla de símbolos
    nodo->lexema = (char *)malloc(strlen(lexema_a_insertar) + 1);
    strcpy(nodo->lexema, lexema_a_insertar);
    // Ahora que nodo tiene la información necesaria, metemos el elemento en el árbol
    insertarElementoAbb(&arbol, *nodo);
}

double recuperarContenidoVarCons(char *lexema) {
    TIPOELEMENTOABB nodoAux;
    nodoAux.lexema = NULL;

    // Tenemos que buscar el nodo con el identificador o clave lexema, si no está se llamará a insertarLexema()
    buscarNodoAbb(arbol, lexema, &nodoAux);

    if (nodoAux.lexema == NULL || nodoAux.type == 1) {
        // Si es null sabemos que la variable no está en la tabla de símbolos, y si es una funcion tampoco nos interesa
        nodoAux.tipo.var = -1;
        devolver = 0; // Desactivamos el valor de la bandera para que no se pueda recibir el valor en el bison, ya que la variable no está en la TS
    }
    return nodoAux.tipo.var;
}

double (*recuperarContenidoFuncion(char *lexema))(void) {
    TIPOELEMENTOABB nodoAux;
    nodoAux.lexema = NULL;

    buscarNodoAbb(arbol, lexema, &nodoAux);

    if (nodoAux.lexema == NULL || nodoAux.type != 1) {
        // Si es null sabemos que la variable no está en la tabla de símbolosla variable
        nodoAux.tipo.fnctptr = NULL;
        devolver = 0; // Desactivamos el valor de la bandera para que no se pueda recibir el valor en el bison, ya que la función no está en la TS
    }
    return nodoAux.tipo.fnctptr;
}

void imprimirTablaSimbolos() {
    printf("\n" GREEN "CONTENIDO DE LA TABLA DE SIMBOLOS:\n" RESET);
    printf(GREEN "----------------------------------------------------------------------------\n" RESET);
    printf(GREEN "%-20s | %-10s | %-7s\n" RESET, "LEXEMA", "VALOR", "TIPO");
    printf(GREEN "----------------------------------------------------------------------------\n" RESET);
    imprimir(arbol);
    printf(GREEN "----------------------------------------------------------------------------\n" RESET);
    printf("\n");
}

void liberarTS() {
    destruirAbb(&arbol);
}

void clear() {
    // llamamos a la funcion que liberará toda la tabla de símbolos excepto las funciones
    limpiarWorkspace(&arbol);
}

int tipoIdentificador(char *lexema) {
    TIPOELEMENTOABB nodoAux;
    nodoAux.lexema = NULL;

    buscarNodoAbb(arbol, lexema, &nodoAux);

    if (nodoAux.lexema == NULL || nodoAux.type == 0) {
        return 0; // Ponemos este valor al tratarse de una variable
    } else if (nodoAux.lexema == NULL || nodoAux.type == 1) {
        return 1; // Ponemos este valor al tratarse de una función
    }
    return 2; // Ponemos este valor al tratarse de una constante
}