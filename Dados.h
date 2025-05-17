/* Created by Rui Oliveira
*
* 17/05/2025
*
*EDA 2024/2024
*
*Gestão de Antenas/Nefastos */


#pragma once

#include <stdbool.h>

#define MAX 30

// Estrutura dos vértices

typedef struct Vertice {
    int x,y;
    char nomeCidade [MAX];
    char freqAntena;
    bool visitado;
    struct Vertice* prox;
    struct AdjD *listaAdjacencias;
}Vertice;

// Estrutura das Adjacências

typedef struct AdjD {
    struct Vertice* destino;
    struct AdjD *prox;
}AdjD;

// Estruruta do grafo GR

typedef struct GR {
    int nVertices;
    Vertice *listaVertices;
}GR;
