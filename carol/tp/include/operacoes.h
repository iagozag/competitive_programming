#ifndef OPERACOES_H
#define OPERACOES_H

#include "pilha_arranjo.h"
#include <string>
using namespace std;

int Prioridade(char c, char t);
string InPos(string* s, string valores);
int Operacao(string* posfixo, string valor);
void transformaEmArray(string entrada, string* s);
void substituiLetras(string& posfixo);

#endif
