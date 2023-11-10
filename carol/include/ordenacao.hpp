#include "grafo.hpp"
/* Comentários disponiveis no arquivo cpp */
void troca(int &v1, int &v2);
int * bolha(int cor[], int n, int vertice[]);
int * selecao(int cor[], int n, int vertice[]);
int * insercao(int cor[], int n, int vertice[]);
void particao(int inicio, int fim, int *i, int *j, int *vertices, int *cores);
void Ordena(int inicio, int fim, int * cores, int * vertices);
int * QuickSort(int cores[], int vertices[], int n);
void Merge(int *cores, int* vertices, int inicio, int fim, int meio);
void MergeSort(int *cores, int *vertices, int inicio, int n);
int * Merge_Sort(int *cores, int *vertices, int n);
void Constroi(int *A, int n, int *vertices);
void Refaz(int Esq, int Dir, int *A, int *vertices);
int * heapSort(int cor[], int n, int vertices[]);
int * meuSort(int cor[], int corMax, int n);
