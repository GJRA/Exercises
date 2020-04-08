// Functions that simulates a Perceptron
// Author: Gabriela Rojano
// File: graph.h
// Date: 07/04/20

#ifndef EX2_H
#define EX2_H


// -----------------------------
// Public interface
// -----------------------------

/* Types declarations */
typedef struct nodoP{
    int entrada1;
    int entrada2;
    int salida;
}NodeP_t;

/* Function prototypes */
/**
 * Display the menu of operators 
 *
 * @return option of the operator selected
 */
int menuC(char stg[]);

/**
 * Start of the neuronal logic
 *
 * @return node with results
 */
int error(int yreal, int yresultado);
/**
 * Start of the neuronal logic
 *
 * @return node with results
 */
int corregir(int wi,int E,int xi);

/**
 * Start of the neuronal logic
 *
 * @return node with results
 */
double checarTD(double e1, double e2);

/**
 * Start of the neuronal logic
 *
 * @return node with results
 */
double errorH(int et1, int et2,double wU1, double wD1,double wU2, double wD2);

/**
 * Start of the neuronal logic
 *
 * @return node with results
 */
void ini();


#endif
