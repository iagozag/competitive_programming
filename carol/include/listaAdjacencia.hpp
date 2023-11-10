#ifndef LISTA_ADJACENCIA_H
#define LISTA_ADJACENCIA_H
#include "../include/listaEncadeada.hpp"

class ListaAdjacencia{
    public:
        ListaAdjacencia(int n);
        ~ListaAdjacencia();
        ListaEncadeada* lista;
        ListaEncadeada* cores;
        void set_tam();
        int get_tam();
        ListaEncadeada adjacente(int pos);
        //int vertices[100];
        void set_arestas();
        int get_aresta();
    
    private:
        int tamanho;
        int arestas;
        
};

#endif