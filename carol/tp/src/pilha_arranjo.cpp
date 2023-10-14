#include "../include/pilha_arranjo.h"

template <typename Tipo> PilhaArranjo<Tipo>::PilhaArranjo()
{
    topo = -1;
}

template class PilhaArranjo<int>;
template class PilhaArranjo<char>;

template <typename Tipo>  PilhaArranjo<Tipo>::~PilhaArranjo(){
    Limpa();
}

template <typename Tipo> void PilhaArranjo<Tipo>::Empilha(Tipo item){
    if(topo+1 == MAXTAM){
        throw "A pilha está cheia!";
    }
    topo++;
    itens[topo] = item;
    
}

template <typename Tipo> Tipo PilhaArranjo<Tipo>::Desempilha(){
    Tipo aux;
    
    if(Vazia()){
       throw "A pilha está vazia";
    }
    
    aux = itens[topo];
    topo--;

    return aux;
}

template <typename Tipo> void PilhaArranjo<Tipo>::Limpa(){
    topo = -1;
}

template <typename Tipo> bool PilhaArranjo<Tipo>::Vazia(){
    if (topo!=-1){
        return false;
    }
    
    return true;
}

template <typename Tipo> int PilhaArranjo<Tipo>::get_tamanho(){
    return topo + 1;
}
