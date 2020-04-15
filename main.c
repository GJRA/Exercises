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
#include "ex2.h"

int main(void) {
    //Ejericio 1
    /*Node_t *nodoSalida = calloc(1, sizeof(Node_t));
    *nodoSalida = inicio();
    if(nodoSalida->pasa){
        printf("Se activa neurona POR ESTRUCTURA\n");
    }else{
        printf("No se activa nada POR ESTRUCTURA\n");
    }
    printf("El resultado fue: %d\n",nodoSalida->resultado);*/
    //Ejercicio 2
    //ini();
    int row = 4;
    int col = 3;
    int **data;
	data = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; ++i){
		data[i] = (int*)malloc(col * sizeof(int));
	}
    read_csv(4,3,"tablaAND.csv",&data);
    ini(4,3,data);
    return 0;
}