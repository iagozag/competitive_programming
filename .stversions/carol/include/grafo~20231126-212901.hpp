#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "../include/listaAdjacencia.hpp"

/* Comentários disponiveis no arquivo cpp */

class Grafo{
    public:
        Grafo(int tamanho);
        ~Grafo();
        void InsereVertice();
        void InsereAresta(int v, int w);
        void InsereCor();
        void AtribuiCor(int v, int w);
        int QuantidadeVertices();
        int QuantidadeArestas();
        void ImprimeVizinhos(int v);
        void ImprimeVizinhosCores(int v);
        int Guloso(int tamanho);
        ListaAdjacencia vertices;
        int* cores;
       
    private:
        int _tamanho;
        
        
};

#endif
