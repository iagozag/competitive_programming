#include "../include/ordenacao.hpp"
#include "../include/memlog.h"
#include <numeric>
#include <iostream>
using namespace std;

/*Função para trocar dois valores v1 e v2.*/
void troca(int &v1, int &v2){
    int parametro = v1;
    v1 = v2;
    v2 = parametro;
}

/* Ordenação por bolha (bubble sort) para ordenar o array de índices 'saida'
com base no array 'cor' em ordem crescente.*/
int * bolha(int cor[], int n, int saida[]){
    int * aux = new int[n];
    int cor_aux[n];
    for (int i =0; i<n; i++){
        aux[i] = saida[i];
        cor_aux[i] = cor[i];
    }

    for(int i = 0; i < n-1; i++){
        for(int j=1;j<n-i;j++){
            if (cor_aux[j] < cor_aux[j-1]){
                troca(cor_aux[j],cor_aux[j-1]);
                troca(aux[j],aux[j-1]);
            } 
        }
    }
    
    return aux;
}

/* Ordenação por seleção para ordenar o array de índices 'vertices' com base no array 'cores'
em ordem crescente, considerando também a ordem original em caso de cores iguais.*/

int * selecao(int cores[], int n, int vertices[]){
    int i, j, min;
    int * aux = new int[n];
    int cor_aux[n];
    for (i =0; i<n; i++){
        aux[i] = vertices[i];
        escreveMemLog((long int)(&(aux[i])), sizeof(int), 1);
        cor_aux[i] = cores[i];
    }


    for(i =0; i < n-1; i++){
        min = i;
        for(j = i+1; j<n; j++){
            leMemLog((long int)(&(aux[j])), sizeof(int), 1);
            leMemLog((long int)(&(aux[min])), sizeof(int), 1);

            if((cor_aux[j] < cor_aux[min])||(cor_aux[min] == cor_aux[j] && aux[j]<aux[min])){
                min = j;           
            }
        }
        troca(cor_aux[i], cor_aux[min]);
        troca(aux[i], aux[min]);

        escreveMemLog((long int)(&(aux[i])), sizeof(int), 1);
        escreveMemLog((long int)(&(aux[min])), sizeof(int), 1);
    }
    return aux;
}

/* Ordenação por inserção para ordenar o array de índices 'organiza' com base no array 'cores'
 em ordem crescente, considerando também a ordem original em caso de cores iguais.*/
int * insercao(int cores[], int n, int vertices[]){
    int i, j;
    int aux, par;
    int*organiza = new int[n];
    int cor_aux[n];
    for (i =0; i<n; i++){
        organiza[i] = vertices[i];
        escreveMemLog((long int)(&(organiza[i])), sizeof(int), 1);
        cor_aux[i] = cores[i];
    }

    for(i =1; i<n; i++){
        aux = cor_aux[i];
        par = organiza[i];
        j = i-1;
        while(((j>=0)&&(aux < cor_aux[j])) || ((j>=0)&&((aux==cor_aux[j])&&(par<organiza[j])))){
            leMemLog((long int)(&(organiza[j])), sizeof(int), 1);
            cor_aux[j+1] = cor_aux[j];
            organiza[j+1] = organiza[j];
            escreveMemLog((long int)(&(organiza[j + 1])), sizeof(int), 1);
            j--;
        }
            cor_aux[j+1] = aux;
            organiza[j+1] = par;
            escreveMemLog((long int)(&(organiza[j + 1])), sizeof(int), 1);
    }
    return organiza;
}

/* Função de partição usada pelo QuickSort para dividir o array em duas partes.*/
void particao(int inicio, int fim, int *i, int *j, int *vertices, int *cores){
    int x, w, y, z;
    *i = inicio; *j = fim;
    x = cores[(*i + *j)/2];
    y = vertices[(*i + *j)/2];
    do{
        while(x > cores[*i] || (x == cores[*i] && y > vertices[*i])) (*i)++;
        while(x < cores[*j] || (x == cores[*j] && y < vertices[*j])) (*j)--;
        if(*i <= *j){
            w = cores[*i]; cores[*i] = cores[*j]; cores[*j] = w;
            z = vertices[*i]; vertices[*i] = vertices[*j]; vertices[*j] = z;
            (*i)++; (*j)--; 
        }
    } while(*i <= *j);
}

/* Função de ordenação rápida (QuickSort) para ordenar o array de índices 'vertices'
com base no array 'cores' em ordem crescente, considerando também a ordem original
em caso de cores iguais. */
void Ordena(int inicio, int fim, int * cores, int * vertices){
    int i, j;
    particao(inicio, fim, &i, &j, vertices, cores);
    if(inicio < j) Ordena(inicio, j, cores, vertices);
    if(i < fim) Ordena(i, fim, cores, vertices);
}

/* Função que realiza o QuickSort para ordenar o array de índices 'vertices' com base no array 'cores'.*/
int * QuickSort(int cores[], int vertices[], int n){
    int* aux = new int[n];
    int* cor = new int[n];
    
    for(int i=0; i<n; i++){
        aux[i] = vertices[i];
        escreveMemLog((long int)(&(aux[i])), sizeof(int), 1);
        cor[i] = cores[i];
    }

    
    Ordena(0, n-1, cor, aux);

    delete[] cor;

    return aux;
}

/*Função para realizar o Merge Sort no array de índices 'vertices' com base no array 'cores'.*/
void Merge(int *cores, int *vertices, int inicio, int fim, int meio) {
    int i, j, k, temp[fim - inicio + 1], aux[fim - inicio + 1];
    i = inicio;
    k = 0;
    j = meio + 1;

    while (i <= meio && j <= fim) {
        if (cores[i] < cores[j] || (cores[i] == cores[j] && vertices[i] < vertices[j])) {
            temp[k] = cores[i];
            aux[k] = vertices[i];
            k++;
            i++;
        } else {
            temp[k] = cores[j];
            aux[k] = vertices[j];
            k++;
            j++;
        }
    }

    while (i <= meio) {
        temp[k] = cores[i];
        aux[k] = vertices[i];
        k++;
        i++;
    }

    while (j <= fim) {
        temp[k] = cores[j];
        aux[k] = vertices[j];
        k++;
        j++;
    }

    for (i = inicio; i <= fim; i++) {
        cores[i] = temp[i - inicio];
        vertices[i] = aux[i - inicio];
    }
}

/* Função que realiza o mergesort do vetor */
void MergeSort(int *cores, int *vertices, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        MergeSort(cores, vertices, inicio, meio);
        MergeSort(cores, vertices, meio + 1, fim);
        Merge(cores, vertices, inicio, fim, meio);
    }
}

int * Merge_Sort(int *cores, int *vertices, int n) {
    MergeSort(cores, vertices, 0, n - 1);
    return vertices;
}

/*Função usada para refazer uma parte do heap em HeapSort.*/
void Refaz(int Esq, int Dir, int *A, int *vertices) {
    int i, j;
    int x, z;
    i = Esq;
    j = 2 * i + 1; 
    x = A[i];
    z = vertices[i];
    
    while (j <= Dir) {
        if (j < Dir && ((A[j] < A[j + 1]) || (A[j] == A[j + 1] &&  vertices[j] < vertices[j+1]))) {
            j++;
        }
        if (x > A[j] || (x == A[j] && z > vertices[j])) {
            break;
        }
        A[i] = A[j];
        vertices[i] = vertices[j];
        i = j;
        j = 2 * i+1; 
    }
    
    A[i] = x;
    vertices[i] = z;
}

/* Função que constrói a estrutura de heap em HeapSort. */
void Constroi(int *A, int n, int *vertices) {
    int Esq;
    Esq = n / 2 - 1; 
    while (Esq >= 0) { 
        Refaz(Esq, n - 1, A, vertices); 
        Esq--;
    }
}

/*Função que realiza o HeapSort para ordenar o array de índices 'vertices' com base no array 'cores'.*/
int * heapSort(int cores[], int n, int vertices[]) {
    int *aux = new int[n];
    int *cor = new int[n];

    for (int i = 0; i < n; i++) {
        aux[i] = vertices[i];
        escreveMemLog((long int)(&(aux[i])), sizeof(int), 1);
        cor[i] = cores[i];
    }

    Constroi(cor, n, aux);
    int Esq = 0;
    int Dir = n - 1;

    while (Dir > 0) { 
        int x = aux[0];
        aux[0] = aux[Dir];
        aux[Dir] = x;

        int z = cor[0];
        cor[0] = cor[Dir];
        cor[Dir] = z;

        Dir--; 
        Refaz(Esq, Dir, cor, aux);
    }
    
    delete[] cor;
    return aux;
    
}

/* Função personalizada para ordenar o array de índices 'cores' com base nos valores de 'cores' em ordem crescente,
mantendo também a ordem original em caso de cores iguais. */
int * meuSort(int cores[], int corMax, int n){
    int * aux = new int[n];
    int k = 0;
    for(int i = 0; i <=corMax; i++){
        for(int j=0; j<n; j++){
            leMemLog((long int)(&(cores[j])), sizeof(int), 1);
            if(cores[j] == i){
                aux[k] = j;
                escreveMemLog((long int)(&(aux[k])), sizeof(int), 1);
                k++;}
        }
    }

    return aux;
}
