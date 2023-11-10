#include "../include/listaAdjacencia.hpp"
/*Construtor da lista de Adjacencia*/
ListaAdjacencia::ListaAdjacencia(int n){
    arestas = 0;
    lista = new ListaEncadeada[n];
    cores = new ListaEncadeada[n];
    tamanho = n;
}

/*Destrutor da lista de Adjacencia*/
ListaAdjacencia::~ListaAdjacencia(){
    delete[] lista;
    delete[] cores;
}

/*Aumenta o tamanho da lista de adjacencia*/
void ListaAdjacencia::set_tam(){
  tamanho++;
}

/*pega o tamanho da lista de adjacencia*/
int ListaAdjacencia::get_tam(){
    return tamanho;
}

/*Retorna a lista de adjacencia de uma determinada posição*/
ListaEncadeada ListaAdjacencia::adjacente(int pos){
    return lista[pos];
}

/*Aumenta a quantidade de arestas*/
void ListaAdjacencia::set_arestas(){
    arestas++;
}

/*Retorna o numero de arestas*/
int ListaAdjacencia::get_aresta(){
    return arestas;
}
