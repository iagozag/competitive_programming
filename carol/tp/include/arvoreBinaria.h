#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include <string>
using namespace std;

class TipoNo{
    public:
        TipoNo();
        int GetTamanho();
    private:
        string item;
        TipoNo *esq;
        TipoNo *dir;

    friend class ArvoreBinaria;
};


class ArvoreBinaria{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();

        void set_expressao(string* exp);
        void Insere(string item);
        void Limpa();
        string PosOrdem(TipoNo *p);
        TipoNo* raiz;

    private:
        void InsereRecursivo(TipoNo* &p, string item);
        void ApagaRecursivo(TipoNo* p);
        string* expressao_logica;

};

string substitui(string entrada, char valor);
int PossuiAE(string entrada);

#endif
