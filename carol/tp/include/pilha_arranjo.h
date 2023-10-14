#ifndef PILHA_ENCADEADA
#define PILHA_ENCADEADA

template <typename Tipo> class PilhaArranjo{
    public:
        PilhaArranjo();
        ~PilhaArranjo();
        
        int get_tamanho();
        void Empilha(Tipo item);
        Tipo Desempilha();
        void Limpa();
        bool Vazia();
private:
    int topo;
    static const int MAXTAM = 1000001;
    Tipo itens[MAXTAM];
};

#endif
