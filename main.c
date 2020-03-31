// Neuronal Logic 
// Author: Gabriela Rojano Arenas
// File: main.c
// Date: 30/03/20

// ------------------------------------------
// System and application specific headers
// ------------------------------------------
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	// Dijkstra's test
	int entradas=0;
    int operacion = menu();
    printf("Escribe cuantas variables de entrada quieres para la neurona ");
    scanf("%d",&entradas);
    int *entrada = calloc(entradas,sizeof(int));
    for(int i = 0; i<entradas; i++){
        printf("Dame el valor de la entrada %d ",i+1);
        scanf("%d",&entrada[i]);
    }
    printf("\n");
    casos(operacion,entrada,entradas);
    return 0;
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

void casos(int operacion, int entrada[], int numEntrada){
    int resultado =0;
    int var = 0;
    switch(operacion){
        case 1: //AND
            for(int i=0; i<numEntrada;i++){
                resultado = resultado + entrada[i];
            } 
            break;
        case 2: //OR
            for(int i=0; i<numEntrada;i++){
                resultado = resultado+(numEntrada*entrada[i]);
            } 
            break;
        case 3: //XOR
            if(entrada[0]!=entrada[1]){
                var = 1;
                printf("Valores 1y 2 diferentes\n");
            }else{
                var = 0;
            }
            if(numEntrada>2){
                for(int i=2; i<numEntrada;i++){
                    if(entrada[i]!=var){
                        var = 1;
                    }else{
                        var = 0;
                    }
                }
            }
            if(var == 1){
                resultado = var*numEntrada;
            }
            break;
        case 4: //NOT
            for(int i=0; i<numEntrada;i++){
                if(entrada[i]==1){
                    resultado = resultado + 0;
                }else{
                    resultado = resultado + 1;
                }
            }
            break;

    }

    if(resultado>=numEntrada){
        printf("Se activa neurona\n");
    }else{
        printf("No se activa nada\n");
    } 
    printf("El resultado fue: %d\n",resultado);
}