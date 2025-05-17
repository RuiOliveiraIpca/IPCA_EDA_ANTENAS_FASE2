/* Created by Rui Oliveira
*
* 17/05/2025
*
*EDA 2024/2024
*
*Gestão de Antenas/Nefastos */


#include "Dados.h"
#include "Funcoes.c"


//Função para criar um Vértice/Antena

Vertice* CriaVertice(int x, int y, const char* nomeCidade, char freqAntena, bool visitado, int *aux);

// Função para criar uma Adjacência

AdjD* CriaAdjacencia(Vertice* destino, int *aux);

// Função para inserir um Vértice/Antena

Vertice* InsereVertice(Vertice* novo, Vertice* inicio, int *aux);

// Função para mostrar no ecrã a lista de vértices

void ImprimeLista(Vertice* inicio);

// Função para remover um Vértice/Antena

Vertice* RemoveVertice(Vertice* inicio, int x, int y, int* aux);

// Função para procurar um Vértices pelas suas coordenadas

Vertice* ProcuraProfundidade(Vertice* atual, int xAlvo, int yAlvo, int* aux);

// Função para procurar uma Cidade no Grafo

Vertice* ProcuraProfundidadeCidade(Vertice* atual, const char* nomeAlvo);