#include "../include/arvoreBinaria.h"
#include "../include/operacoes.h"
#include <iostream>

using namespace std;

TipoNo::TipoNo(){
    item = "";
    esq = NULL;
    dir = NULL;
}

int TipoNo::GetTamanho(){
    int i = 0;
    while(item[i]!='\0'){
        i++;
    }
    return i+1;
}

ArvoreBinaria::ArvoreBinaria(){
    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}

void ArvoreBinaria::set_expressao(string* exp){
    expressao_logica = exp;
}

void ArvoreBinaria::Insere(string item){
    InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, string item){
        p = new TipoNo();
        p->item = item;
        //modificar isso dps para os criterios
        if(!PossuiAE(item)){
            return;
        }       
        InsereRecursivo(p->esq, substitui(item,'0'));
        InsereRecursivo(p->dir, substitui(item,'1'));
}

string ArvoreBinaria::PosOrdem(TipoNo *p){
    if(p!=NULL){
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        
        if((p->esq != nullptr) & (p->dir != nullptr)){
            char letra_atual = '0';
            for(int i = 0; i < p->GetTamanho(); i++){
                string letra = "";
                letra += p->item[i];
                if(PossuiAE(letra)){
                    letra_atual = p->item[i];
                    break;
                }
            }

            if(letra_atual == 'e'){
                if((Operacao(expressao_logica, p->esq->item) == 0) && (Operacao(expressao_logica, p->dir->item) == 0)){
                    p->item = "-1";
                    return "-1";
                } 
                else if((Operacao(expressao_logica, p->esq->item) == 1) && (Operacao(expressao_logica, p->dir->item) == 1)){
                    for(int i = 0; i < p->GetTamanho(); i++){
                        if((p->esq->item[i] == '0' && p->dir->item[i] == '1') || (p->esq->item[i] == '1' && p->dir->item[i] == '0')){
                            p->item[i] = 'a';
                        }
                        else if(p->esq->item[i] == 'a'){
                            p->item[i] = p->dir->item[i];
                        }
                        else if(p->dir->item[i] == 'a'){
                            p->item[i] = p->esq->item[i];
                        }
                        else p->item[i] = p->esq->item[i];
                    }
                } 
                else if(Operacao(expressao_logica, p->esq->item) == 1){
                    p->item = p->esq->item;
                } 
                else{
                    p->item = p->dir->item;
                }
            }
            else if(letra_atual == 'a'){
                if((Operacao(expressao_logica, p->esq->item) == 0) || (Operacao(expressao_logica, p->dir->item) == 0)){
                    p->item = "-1";
                    return "-1";
                }
                
                for(int i = 0; i < p->GetTamanho(); i++){
                    if((p->esq->item[i] == '0' && p->dir->item[i] == '1') || (p->esq->item[i] == '1' && p->dir->item[i] == '0')){
                        p->item[i] = 'a';
                    }
                    else if(p->esq->item[i] == 'a'){
                        p->item[i] = p->dir->item[i];
                    }
                    else if(p->dir->item[i] == 'a'){
                        p->item[i] = p->esq->item[i];
                    }
                    else p->item[i] = p->esq->item[i];
                }
            }
        }
    }

    return raiz->item;
}

void ArvoreBinaria::Limpa(){
    ApagaRecursivo(raiz);
    raiz = NULL;

}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
    if(p!=NULL){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

string substitui(string entrada, char valor){
    string parametro = entrada;
    int i = 0;
    while(parametro[i]!= '\0'){
        if((parametro[i]=='a') || (parametro[i] == 'e')){
            parametro[i] = valor;
            break; 
        }
        i++;
    }

    return parametro;
}

int PossuiAE(string entrada){
    int i = 0;
    while(entrada[i] != '\0'){
        if((entrada[i]=='a') || (entrada[i] == 'e')){
            return 1;
        }
        i++;
    }
    return 0;
}
