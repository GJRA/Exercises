// Neuronal Logic 
// Author: Gabriela Rojano Arenas
// File: main.c
// Date: 30/03/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ex1.h"

int main(void) {
    Node_t *nodoSalida = calloc(1, sizeof(Node_t));
    *nodoSalida = inicio();
    if(nodoSalida->pasa){
        printf("Se activa neurona POR ESTRUCTURA\n");
    }else{
        printf("No se activa nada POR ESTRUCTURA\n");
    }
    printf("El resultado fue: %d\n",nodoSalida->resultado);
    return 0;
}