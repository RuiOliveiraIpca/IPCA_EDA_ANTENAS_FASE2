/* Created by Rui Oliveira
*
* 17/05/2025
*
*EDA 2024/2024
*
*Gestão de Antenas/Nefastos */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Dados.h"

// Função para criar um novo vértice
// Questionar LUFER porque a correção para const char*

Vertice* CriaVertice(int x, int y, const char* nomeCidade, char freqAntena, bool visitado, int *aux) {
    Vertice* novoVertice  = (Vertice*) malloc(sizeof(Vertice));
    *aux=0;
    if (novoVertice != NULL) {
        novoVertice->x = x;
        novoVertice->y = y;
        strncpy(novoVertice->nomeCidade, nomeCidade, MAX);
        novoVertice->freqAntena = freqAntena;
        novoVertice->visitado = false;
        novoVertice->prox = NULL;
        *aux = 1;
    } return novoVertice;
}

// Função para criar uma Adjacência

AdjD* CriaAdjacencia(Vertice* destino, int *aux) {
    AdjD* novaAdj = (AdjD*) malloc(sizeof(AdjD));
    *aux = 0;
    if (novaAdj != NULL) {
        novaAdj->destino = destino;
        novaAdj->prox = NULL;
        *aux = 1;
        return novaAdj;
    }
}

Vertice* InsereVertice(Vertice* novo, Vertice* inicio, int *aux) {
    *aux = 0;
    if (inicio == NULL ) {
        *aux = 1;
        return novo;  // novo se torna-se o inicio da lista se a lista estiver vazia
    }
    if (novo->x < inicio->x || (novo->x == inicio->x && novo->y < inicio->y)) {
        novo->prox = inicio;
        *aux = 1;
        return novo; // insere no inicio da lista
    }else{
        Vertice *antes = inicio;
        Vertice *depois = inicio;
       while (depois != NULL &&
             (depois->x < novo->x || (depois->x == novo->x && depois->y < novo->y))) {
            antes = depois;
            depois = depois->prox;
       }
        novo->prox = depois;
        antes->prox = novo;
        *aux = 1;
        return inicio; // insere de forma ordenada
        }
    }

// Imprime a lista de Antenas
void ImprimeLista(Vertice* inicio) {
    Vertice* atual = inicio;
    while (atual != NULL) {
        printf("Cidade: %s (%d, %d), Antena: %c\n",
               atual->nomeCidade, atual->x, atual->y, atual->freqAntena);
        atual = atual->prox;
    }
}

Vertice* RemoveVertice(Vertice* inicio, int x, int y, int *aux){
    *aux = 0;
    Vertice* atual = inicio;
    Vertice* anterior = NULL;

    // Procura o vértice pretendido
    while (atual != NULL && !(atual->x == x && atual->y == y)) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return inicio; // Vértice não encontrado
    }

    if (anterior == NULL) {
        inicio = atual->prox;  // Caso seja o primeiro vértice
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    *aux = 1;
    return inicio;
}

// Procura apenas os vértices em profundidade, questionar LUFER como procurar nas adjacências

Vertice* ProcuraProfundidade(Vertice* atual, int xAlvo, int yAlvo, int *aux) {
    *aux = 0;
    if (atual == NULL || atual->visitado)
        return *aux;

    atual->visitado = true;

    // Se encontrou o vértice nas coordenadas desejadas
    if (atual->x == xAlvo && atual->y == yAlvo)
        *aux = 1;
        return atual;

}


Vertice* ProcuraProfundidadePorNome(Vertice* atual, const char* nomeAlvo) {
    if (atual == NULL || atual->visitado)
        return NULL;

    atual->visitado = true;

    if (strcmp(atual->nomeCidade, nomeAlvo) == 0)
        return atual;

    AdjD* adj = atual->listaAdjacencias;
    while (adj != NULL) {
        Vertice* resultado = ProcuraProfundidadePorNome(adj->destino, nomeAlvo);
        if (resultado != NULL)
            return resultado;
        adj = adj->prox;
    }

    return NULL;
}