#include "../include/grafo.hpp"
#include "../include/ordenacao.hpp"
#include "../include/memlog.h"
#include <iostream>
using namespace std;
 
int main(){
    char lognome[100] = "teste/data.out";
    iniciaMemLog(lognome);

    ativaMemLog();

    defineFaseMemLog(0);
    int n, adj, ligado, cor, corMax = -1;
    char c;
    cin >> c;
    cin >> n;
    int vertices[n];
    int cores[n];

    for(int i = 0; i<n; i++){
        vertices[i] = i; // Inicializa os vértices com valores sequenciais.
    }
    
    Grafo g = Grafo(n);

    /*insere arestas adjacentes*/
    for(int i=0; i<n;i++){
        cin >> adj;
        for(int j = 0; j < adj; j++){
            cin >> ligado;
            g.InsereAresta(i, ligado);
        }
    }
    
    /*atribui o valor das cores ao array de cores*/
    for(int i=0; i<n;i++){
            cin >> cor;
            cores[i] = cor;
            g.AtribuiCor(i, cor);
            if(cor > corMax){
                corMax = cor; 
            }
    }
  
    /*cria uma lista de adjacencia com as cores*/
    g.InsereCor();

    int*organizado = new int[n];
    defineFaseMemLog(1);
    /*se for guloso, ordenar de acordo com o tipo de ordenação escolhido*/
    if(g.Guloso(n) == 0){
        cout << 0 << endl;
    }
    else{
        int*organizado = new int[n];
        switch ((c))
        {   
            case 'b':
                organizado = bolha(cores,n,vertices);               
                break;
            case 's':
                organizado = selecao(cores, n, vertices);
                break;
            case 'i':
                organizado = insercao(cores, n, vertices);
                break;
            case 'q':
                organizado = QuickSort(cores, vertices, n);
                break;
            case 'm':
                organizado = Merge_Sort(cores,vertices, n);
                break;
            case 'p':
                organizado = heapSort(cores, n, vertices);
                break;
            case 'y':
                organizado = meuSort(cores, corMax, n);
                break;
        }

        /*Imprime 1 e os vertices ordenados por cor e vértice*/
        cout << 1 << " ";
        for(int i =0; i<n; i++){
            leMemLog((long int)(&(organizado[i])),sizeof(int),1);
            cout << organizado[i] << " ";
        }
        cout<<endl;
    }

    defineFaseMemLog(2);
    delete[] organizado;
    for(int i = 0; i < n; i++) g.ImprimeVizinhos(i);
    for(int i = 0; i < n; i++) g.ImprimeVizinhosCores(i);

    return finalizaMemLog();
}
