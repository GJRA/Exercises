// See ex2.h for more info
// Author: Gabriela Jaquelina Rojano Arenas
// File: ex2.c
// Date: 07/04/20

// ------------------------------------------
// System and aplication specific headers
// ------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "ex2.h"
// -----------------------------
// Private elements
// -----------------------------

/* Private types */
int Threshold = 1;

void ini(int row, int col,int **data) {
    srand((unsigned int)time(NULL));
    int capas = menuC("cuantas capas quieres");
    int nodos = menuC("cuantos nodos en cada capa quieres");
    int e = 1;
    int e2 =1;
    srand ( time(NULL) );
    NodeP_t *nodo1 = calloc(1, sizeof(NodeP_t));
    NodeP_t *nodo2 = calloc(1, sizeof(NodeP_t));
    for(int k=0;k<row;k++){
        nodo1->entrada1 = data[k][0];
        nodo1->entrada2 = data[k][1];
        nodo1->salida = data[k][2];
        nodo2->entrada1 = data[k][0];
        nodo2->entrada2 = data[k][1];
        nodo2->salida = data[k][2];
        double w[2][2];
        w[0][0]= (float)rand()/RAND_MAX;
        w[0][1]= (float)rand()/RAND_MAX;
        w[1][0]= (float)rand()/RAND_MAX;
        w[1][1]= (float)rand()/RAND_MAX;
        int var,var2;
        var = checarT(nodo1->entrada1,nodo1->entrada2);
        var2 = checarT(nodo2->entrada1,nodo2->entrada2);
        double re,re2,eh1,eh2,k,k1;
        while (e!=0 && e2!=0){
            k=(double)var;
            k1=(double)var2;
            k= (w[0][0]);
            k1=(w[1][0]);
            re = checarTD(k,k1);
            k=(double)(w[0][1] * var);
            k1=(double)(var2 * w[1][1]);
            re2 = checarTD(k,k1);
            e = error(nodo1->salida,re);
            e2 = error(nodo1->salida,re2);
            printf("Error %ld Error 2 %ld\n",e,e2);
            if (e!=0){
                eh1=errorH(e,e2,w[0][0],w[1][0],w[0][1],w[1][1]);
                eh2=errorH(e,e2,w[1][0],w[0][0],w[1][1],w[0][1]);
                w[0][0]=corregir(w[0][0],eh1,nodo1->entrada1);
                w[0][1]=corregir(w[0][1],eh1,nodo1->entrada1);
                w[0][0]=corregir(w[1][0],eh2,nodo1->entrada2);
                w[0][0]=corregir(w[1][0],eh2,nodo1->entrada2);
            }
        }
    }
}


double errorH(int et1, int et2,double wU1, double wD1,double wU2, double wD2){
    double resultado=1;
    double et1d = (double) et1;
    double et2d = (double) et2;
    resultado = ((wU1/(wU1+wD1))*et1d)+((wU2/(wU2+wD2))*et2d);
    return resultado;
}

int checarT(int e1, int e2){
    int re=0;
    if ((e1+e2) >= Threshold){
        re = 1;
    }
    return re;
}

double checarTD(double e1, double e2){
    int re=0;
    if ((e1+e2) >= Threshold){
        re = 1;
    }
    return re;
}

int menuC(char stg[]){
    int num = 0;
    printf("Escribe %s\n",stg);
    scanf("%d",&num);
    return num;
}

int error(int yreal, int yresultado){
    return (yreal-yresultado);
}

int corregir(int wi,int E,int xi){
    int n = 0.05;
    int resultado;
    resultado = wi+(n*E*xi);
    return resultado;
}

void read_csv(int row, int col, char *filename,int ***data){
	FILE *file;
	file = fopen(filename, "r");

	int i = 0;
    char line[4098];
    
    while (fgets(line, 4098, file) && (i < row))
    {
        const char* tmp = strdup(line);
        int j = 0;
        int l = 0;
        int x = 0;
        while(tmp[l]!='\0')
        {
            if (tmp[l] != ',' && x < (row-1)){
                char v[3];
                v[0]='0';
                v[1]=tmp[l];
                v[2]='\0';
                int k = atoi(v);
                (*data)[i][j] = k;        
                j++;
                x++;
            }
            l++;
        }
        free(tmp);
        i++;
    }
}











