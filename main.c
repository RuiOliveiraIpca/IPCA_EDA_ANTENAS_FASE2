/* Created by Rui Oliveira
*
* 17/05/2025
*
*EDA 2024/2024
*
*Gestão de Antenas/Nefastos */


#include <stdio.h>
#include "Dados.h"
#include "Funcoes.h"




int main() {
    Vertice* lista = NULL;
    int aux;

    // Criação e inserção de 5 vértices - Testes criados pelo CHATGPT


    lista = InsereVertice(CriaVertice(3, 2, "Cidade C", 'C', false, &aux), lista, &aux);
    lista = InsereVertice(CriaVertice(1, 5, "Cidade A", 'A', false, &aux), lista, &aux);
    lista = InsereVertice(CriaVertice(2, 3, "Cidade B", 'B', false, &aux), lista, &aux);
    lista = InsereVertice(CriaVertice(1, 2, "Cidade D", 'D', false, &aux), lista, &aux);
    lista = InsereVertice(CriaVertice(3, 1, "Cidade E", 'E', false, &aux), lista, &aux);

    // Impressão da lista
    printf("Lista de vértices ordenados por (x, y):\n");
    ImprimeLista(lista);


    int xBusca = 1, yBusca = 2;
    Vertice* encontrado = ProcuraProfundidade(lista, xBusca, yBusca, &aux);

    if (encontrado != NULL) {
        printf("Vértice encontrado: %s (%d, %d)\n", encontrado->nomeCidade, encontrado->x, encontrado->y);
    } else {
        printf("Vértice com coordenadas (%d, %d) não encontrado.\n", xBusca, yBusca);
    }

    /* Não está a funcionar

    inicio = lista;
    inicio = RemoveVertice(lista, 1 , 2 , &aux);
    if (aux)
        printf("Vértice removido com sucesso.\n");
    else
        printf("Vértice não encontrado.\n");
    */


    /* Não encontra cidades
     *
    Vertice* achado = ProcuraProfundidadeCidade(lista, "Cidade A");

    if (achado != NULL) {
        printf("Encontrou: %s na posição (%d,%d), antena %c\n",
               achado->nomeCidade, achado->x, achado->y, achado->freqAntena);
    } else {
        printf("Cidade não encontrada.\n");
    }
    */

    return 0;


}
