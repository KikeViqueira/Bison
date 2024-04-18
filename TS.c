#include "TS.h"
#include "abb.h"
#include <malloc.h>
#include <string.h>

#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

TABB arbol;

void initTS() {

    // Creamos la estructura base del árbol
    crearAbb(&arbol);

    // Imprimimos el árbol para ver si se ha creado de manera correcta
    printf(GREEN "\nCONTENIDO INICIAL DE NUESTRA TABLA DE SIMBOLOS: \n" RESET);
    printf(GREEN "----------------------------------------------------------\n" RESET);
    imprimir(arbol);
    printf("\n");
}

void buscarLexema(token *componente) {
    // Hacemos una copia del nodo, así aunque se libere la memoria del token en otra parte del código, en el árbol seguiremos con su información
    TIPOELEMENTOABB nodoAux;
    nodoAux.lexema=NULL;

    // Tenemos que buscar el nodo con el identificador o clave lexema, si no está se llamará a insertarLexema()
    buscarNodoAbb(arbol, componente->lexema, &nodoAux);

    if (nodoAux.lexema == NULL) {
        /*Si se entra aqui es porque la función buscarnodo no ha encontrado ningún nodo cuya clave coincida con el lexema
         que se ha pasado como clave, en el caso de no entrar en el if ya hemos encontrado el nodo*/
        insertarLexema(componente->lexema, &nodoAux);
    }

    componente->value = nodoAux.value;
}

void insertarLexema(char *lexema_a_insertar, TIPOELEMENTOABB *nodo) {
    // tenemos que hacer una copia del lexema cuando lo metamos en la TS, porque si no cuando el sintáctico hago un free del token este se borrará también de la tabla de símbolos
    nodo->lexema = (char *)malloc(strlen(lexema_a_insertar) + 1);
    strcpy(nodo->lexema, lexema_a_insertar);


    // Ahora que nodo tiene la información necesaria, metemos el elemento en el árbol
    insertarElementoAbb(&arbol, *nodo);
}




/*void buscarLexema(token *componente) {
    // Hacemos una copia del nodo, así aunque se libere la memoria del token en otra parte del código, en el árbol seguiremos con su información
    TIPOELEMENTOABB nodoAux;
    nodoAux.numToken = 0;

    // Tenemos que buscar el nodo con el identificador o clave lexema, si no está se llamará a insertarLexema()
    buscarNodoAbb(arbol, componente->lexema, &nodoAux);

    if (nodoAux.numToken == 0) {
        /*Si se entra aqui es porque la función buscarnodo no ha encontrado ningún nodo cuya clave coincida con el lexema
         que se ha pasado como clave, en el v¡caso de no entrar en el if ya hemos encontrado el nodo y devolvemos número correspondiente al lexema*/
        /*insertarLexema(componente->lexema, &nodoAux);
    }

    componente->numToken = nodoAux.numToken;
}*/

/*void insertarLexema(char *lexema_a_insertar, TIPOELEMENTOABB *nodo) {
    // tenemos que hacer una copia del lexema cuando lo metamos en la TS, porque si no cuando el sintáctico hago un free del token este se borrará también de la tabla de símbolos
    nodo->lexema = (char *)malloc(strlen(lexema_a_insertar) + 1);
    strcpy(nodo->lexema, lexema_a_insertar);
    nodo->numToken = ID;

    // Ahora que nodo tiene la información necesaria, metemos el elemento en el árbol
    insertarElementoAbb(&arbol, *nodo);
}*/

void imprimirTablaSimbolos() {
    printf(GREEN "\nCONTENIDO DE NUESTRA TABLA DE SIMBOLOS DESPUES DE PROCESAR EL ARCHIVO: \n" RESET);
    printf(GREEN "----------------------------------------------------------------------------\n" RESET);
    imprimir(arbol);
}

void liberarTS() {
    destruirAbb(&arbol);
}