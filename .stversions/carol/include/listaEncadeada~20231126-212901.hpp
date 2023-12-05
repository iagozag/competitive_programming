#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

class TipoCelula{
    public:
    TipoCelula(){
        prox = nullptr;  
        numero = -1;
    }
        int numero;
        int cor;
    private: 
        TipoCelula* prox;

    friend class ListaEncadeada;
};

class ListaEncadeada{
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        bool Vazia();
        int GetTamanho();
        int GetItem(int pos);
        int GetCor(int pos);
        void SetItem(int item, int pos);
        void InsereInicio(int item);
        void InsereFinal(int item);
        int pesquisa(int c);
        void Imprime();
        void Limpa();
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);

    protected:
        int tamanho;
        
};


#endif
