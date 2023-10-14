#include <iostream>
#include "../include/pilha_arranjo.h"
#include "../include/operacoes.h"
#include "../include/arvoreBinaria.h"
using namespace std;
#include <string>
#include <getopt.h>

const int MAXLEN = 1000001;

int main(int argc, char ** argv){
    ArvoreBinaria p;
    int c;
    string entrada, infixo, resposta;
    string* infixoT = new string[MAXLEN];

    while((c = getopt(argc, argv,"a:s:")) != -1){
        switch (c)
        {
        case 'a':
            infixo = optarg;
            entrada = argv[optind];
            transformaEmArray(infixo, infixoT);
            cout << Operacao(infixoT, entrada) << endl;
            break;
        
        case 's':
            infixo = optarg;
            entrada = argv[optind];
            transformaEmArray(infixo, infixoT);
            p.Insere(entrada);
            p.set_expressao(infixoT);
            resposta = p.PosOrdem(p.raiz);
            if(resposta != "-1"){
                cout << 1 << " " << resposta << endl;
            }else{
                cout << 0 << endl;
            }

            break;
        }
    }

    delete[] infixoT;
    return(0);
}
