#include "../include/operacoes.h"
#include <iostream>

int Prioridade(char c, char t){
    int pc, pt;

    if(c=='~'){
        pc = 4;
    }
    else if(c=='&'){
        pc = 2;
    } 

    else if(c== '|'){
        pc = 1;
    }
    else if(c == '('){
        pc = 4;
    }

    if(t=='~'){
        pt = 3;
    }
    else if(t=='&'){
        pt = 2;
    } 
    else if(t== '|'){
        pt = 1;
    }
    if(t == '('){
        pt = 0;
    }

    return (pc > pt);
    
}

string InPos(string* s, string valores){
    PilhaArranjo<char> p;
    int i = 0;
    string c;
    char t;
    string saida = "";
    p.Empilha('(');

    do{
        c = s[i];
        i++;
        if(c == "("){
            p.Empilha('(');
        }
        else if(c == ")" || c == "-1"){
            do {
                t = p.Desempilha();
                if( t != '('){
                    saida += t;
                }
            }while(t != '(');
            
            
        }
        else if(c == "&" || c == "|" || c == "~"){
            while(1){
                char a = c[0];
                t = p.Desempilha();
                if(Prioridade(a, t)){
                    p.Empilha(t);
                    p.Empilha(a);
                    break;
                }
                else{
                    saida += t;
                }
            }
        }
        else{
            char ch = valores[stoi(c)];
            saida += ch;
        }
    }while(c != "-1");

    return saida;
}

int Operacao(string* s, string valor){
    if(valor == "-1") return 0;

    string posfixoT = InPos(s, valor);
    substituiLetras(posfixoT);

    PilhaArranjo<int> p;
    char c;
    int i = 0;
    do{
        c = posfixoT[i];
        i++;
        if(c == '0' || c == '1'){
            p.Empilha(c-'0');
        }
        else if(c == '~'){
            int d = p.Desempilha();
            if(d == 0){
                p.Empilha(1);
            }else{
                p.Empilha(0);
            }
        }
        else if(c == '|'){
            int a, b;
            a = p.Desempilha();
            b = p.Desempilha();
            p.Empilha(a | b);
        }
        else if(c == '&'){
            int a, b;
            a = p.Desempilha();
            b = p.Desempilha();
            p.Empilha(a & b);
        }

    }while(c != '\0');

    return p.Desempilha(); 
}

void transformaEmArray(string entrada, string* s){
    string temp = "";
    int i = 0, j = 0;
    while(entrada[i] != '\0'){
        if(entrada[i] == ' '){
            s[j] = temp;
            temp = "";
            j++;
        }
        else{
            temp += entrada[i];
        }

        i++;
    }

    string final = "";
    final += temp;
    s[j] = final;
    j++;
    s[j] = "-1";
}

void substituiLetras(string& posfixo){
    int i = 0;
    while(posfixo[i] != '\0'){
        if(posfixo[i] == 'a'){
            posfixo[i] = '0';
        }
        i++;
    }

}
