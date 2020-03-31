/*Bitwise y estructuras generar AND OR XOR y NOT  para un threshold en general*/
// See graph.h for more info
// Author: Gabriela Jaquelina Rojano Arenas
// File: 
// Date: 30/03/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------
#include <stdlib.h>


// -----------------------------
// Private elements
// -----------------------------

/* Private macros and constants */

#define THRES 2

/* Private functions */

/**
 * Translates a direction to its corresponding bitmask.
 *
 * @param from Direction to translate.
 * @return Corresponding bitmask.
 */
/*static int8_t getMask( Direction_t from ) {
	return masks[from];
}*/

// -----------------------------
// Public elements
// -----------------------------

/* Implementation of the public functions */

void menu(){
    int entradas=0;
    printf("El Threshold para la red neuronal es: %d\n",THRES);
    printf("Escribe cuantas variables de entradas quieren para la neurona");
    scanf("%d",&entradas);
    int entrada = calloc(entradas,sizeof(int));
    for(int i = 0; i<entradas; i++){
        printf("Dame el valor de la entrada %d",i+1);
        scanf("%d",&entrada[i]);
    }
}