#include "../include/grafo.hpp"
#include <iostream>
using namespace std;

/*Construtor da classe grafo*/
Grafo::Grafo(int tamanho) : vertices(tamanho)
{
    _tamanho = tamanho;
    cores = new int[_tamanho];
}
/*destrutor da classe grafo*/
Grafo::~Grafo()
{
    delete[] cores;
}

/*insere o vertice no grafo*/
void Grafo::InsereVertice()
{
    vertices.set_tam();
}

/*insere uma aresta no grafo*/
void Grafo::InsereAresta(int v, int w)
{
    vertices.lista[v].InsereFinal(w);
    vertices.set_arestas();
}

/*retorna a quantidade de vertices*/
int Grafo::QuantidadeVertices()
{
    return _tamanho;
}

/*retorna a quantidade de arestas*/
int Grafo::QuantidadeArestas()
{
    return (vertices.get_aresta() / 2);
}

/*imprime os vizinhos do vertice*/
void Grafo::ImprimeVizinhos(int v)
{
    vertices.lista[v].Imprime();
}

void Grafo::ImprimeVizinhosCores(int v){
    vertices.cores[v].Imprime();
}

/*cria uma lista de cores adjacentes*/
void Grafo::InsereCor()
{
    for (int i = 0; i < _tamanho; i++)
    {
        for (int j = 0; j < vertices.lista[i].GetTamanho(); j++)
        {
            vertices.cores[i].InsereFinal(cores[vertices.lista[i].GetItem(j)]);
        }
    }
}

/*atribui uma cor a cada vertice*/
void Grafo::AtribuiCor(int v, int w)
{
    cores[v] = w;
}
/*
Verifica se o grafo é guloso com base nas cores dos vertices adjacentes a ele
*/
int Grafo::Guloso(int tamanho){
    for(int i = 0; i<tamanho;i++){
        int j = 0, k=0;
        int visitou[cores[i]]; //cor do vertice atual
        while(k < cores[i]){ //cor do vertice atual
            visitou[k] = -1;
            k++;
        }
        
        while (j < vertices.cores[i].GetTamanho())
        {   //pega a cor na posiçao j
            
            if(vertices.cores[i].Posiciona(j,0)->numero < cores[i]){
                visitou[vertices.cores[i].Posiciona(j,0)->numero] = vertices.cores[i].Posiciona(j,0)->numero;
            }
            j++;
        }

        for (int l = 1; l<cores[i];l++){
            if(visitou[l]==-1){
                return 0;
            }
        }
    }
    return 1;
}
