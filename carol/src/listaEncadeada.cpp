#include "../include/listaEncadeada.hpp"
#include "../include/memlog.h"
#include <iostream>
using namespace std;
/*Construtor listaEncadeada*/
ListaEncadeada::ListaEncadeada(){
    primeiro = new TipoCelula();
    ultimo = primeiro;
    tamanho = 0;
}
/*Destrutor ListaEncadeada*/
ListaEncadeada::~ListaEncadeada(){
    Limpa();
    delete primeiro;
}

/*verifica se a lista está vazia*/
bool ListaEncadeada::Vazia(){
    if (tamanho!=0){
        return false;
    }else{return true;}
}

/*Retorna o tamanho da lista*/
int ListaEncadeada::GetTamanho(){
    return tamanho;
}

/*posiciona na lista*/
TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes=false){
    TipoCelula* p; int i;
    if ((pos>=tamanho)|| (pos<0)){
        throw "ERRO: Posicao Invalida!";
    }

    p = primeiro->prox;
    leMemLog((long int)(p),sizeof(TipoCelula),0);
    for(i=0; i<pos; i++){
        p = p->prox;
        leMemLog((long int)(p),sizeof(TipoCelula),0);
    }

    return p;

}
/*retorna o valor do item*/
int ListaEncadeada::GetItem(int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    leMemLog((long int)(&(p->numero)),sizeof(int),0);
    return p->numero;
}

/*retorna a cor do item*/
int ListaEncadeada::GetCor(int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    leMemLog((long int)(&(p->cor)),sizeof(int),0);
    return p->cor;
}

/*define o item*/
void ListaEncadeada::SetItem(int item, int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    p->numero = item;
    escreveMemLog((long int)(&(p->numero)),sizeof(int),0);
}

/*Insere no inicio da lista*/
void ListaEncadeada::InsereInicio(int item){
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->numero = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

    if(nova->prox == nullptr){
        ultimo = nova;
    }
}

/*insere no final da lista*/
void ListaEncadeada::InsereFinal(int item){
    TipoCelula* nova;
    nova = new TipoCelula();
    nova->numero = item;
    ultimo->prox = nova;
    tamanho++;
    ultimo=nova;
    escreveMemLog((long int)(nova),sizeof(TipoCelula),0);
}

/*pesquisa na lista*/
int ListaEncadeada::pesquisa(int c){
    int aux;
    TipoCelula *p;
    if(Vazia()){
        throw "ERRO: lista vazia";
    }
    p = primeiro->prox;
    aux = -1;
    while(p!=nullptr){
        if(p->numero == c){
            aux = p->numero;
            break;
        }
    p = p->prox;
    }
    return aux;
}

/*Imprime a lista*/
void ListaEncadeada::Imprime(){
    TipoCelula *p;
    p = primeiro->prox;
    while (p!=nullptr)
    {
        leMemLog((long int)(p),sizeof(TipoCelula),0);
        cout << p->numero << " ";
        p = p->prox;
    }
    cout << endl;
}

/*Limpa a lista encadeada*/
void ListaEncadeada::Limpa(){
    TipoCelula *p;
    p = primeiro->prox;
    while(p!=nullptr){
        leMemLog((long int)(p),sizeof(TipoCelula),0);
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}
