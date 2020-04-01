/*Bitwise y estructuras generar AND OR XOR y NOT  para un threshold en general*/
// See graph.h for more info
// Author: Gabriela Jaquelina Rojano Arenas
// File: ex1.c
// Date: 30/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ex1.h"
// -----------------------------
// Private elements
// -----------------------------

/* Private types */

Node_t inicio() {
    Node_t *nodo1 = calloc(1, sizeof(Node_t));
    nodo1->operacion=menu();
    printf("Escribe cuantas entradas quieres para la neurona ");
    scanf("%d",&nodo1->numEntradas);//Para esto mi Threshold es igual al num entradas.
    int *entrada = calloc(nodo1->numEntradas,sizeof(int));
    for(int i = 0; i<nodo1->numEntradas; i++){
        printf("Dame el valor de la entrada %d ",i+1);
        scanf("%d",&entrada[i]);
    }
    printf("\n");
    return casos(entrada,nodo1);
}

int menu(){
    int num = 0;
    printf("Escoge el num de la operación deseas hacer\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    scanf("%d",&num);
    return num;
}

Node_t casos(int entrada[], Node_t *nodo1){
    int resultado =0;
    int var = 0;
    switch(nodo1->operacion){
        case 1: //AND
            for(int i=0; i<nodo1->numEntradas;i++){
                resultado = resultado + entrada[i];
            } 
            nodo1->resultado=resultado;
            if(resultado == nodo1->numEntradas){
                nodo1->pasa=true;
            }else{
                nodo1->pasa=false;
            }
            break;
        case 2: //OR
            for(int i=0; i<nodo1->numEntradas;i++){
                resultado = resultado+(nodo1->numEntradas*entrada[i]);
            }
            nodo1->resultado=resultado; 
            if(resultado >= nodo1->numEntradas){
                nodo1->pasa=true;
            }else{
                nodo1->pasa=false;
            }
            break;
        case 3: //XOR
            if(entrada[0]!=entrada[1]){
                var = 1;
            }else{
                var = 0;
            }
            if(nodo1->numEntradas>2){
                for(int i=2; i<nodo1->numEntradas;i++){
                    if(entrada[i]!=var){
                        var = 1;
                    }else{
                        var = 0;
                    }
                }
            }
            if(var == 1){
                resultado = var*nodo1->numEntradas;
                nodo1->resultado=resultado;
                nodo1->pasa=true;
            }else{
                nodo1->pasa = false;
                nodo1->resultado = 0;
            }
            break;
        case 4: //NOT
            for(int i=0; i<nodo1->numEntradas;i++){
                if(entrada[i]==1){
                    resultado = resultado + 0;
                }else{
                    resultado = resultado + 1;
                }
            }
            nodo1->resultado=resultado;
            if(resultado >= nodo1->numEntradas){
                nodo1->pasa=true;
            }else{
                nodo1->pasa=false;
            }
            break;

    }
    return *nodo1;
}