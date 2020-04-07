// Functions that simulates a node with basic operators
// Author: Gabriela Rojano
// File: graph.h
// Date: 30/03/20

#ifndef EX1_H
#define EX1_H


// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */
typedef struct nodo {
	bool pasa;
    int numEntradas;
    int operacion;
    int resultado;
}Node_t;


/* Function prototypes */
/**
 * Display the menu of operators 
 *
 * @return option of the operator selected
 */
int menu();

/**
 * Start of the neuronal logic
 *
 * @return node with results
 */
Node_t inicio();

/**
 * Do the operator logic with the given inputs
 *
 * @param entrada array of inputs
 * @param nodo1 struct node
 * @return node with results
 */
Node_t casos(int entrada[], Node_t *nodo1);

#endif
