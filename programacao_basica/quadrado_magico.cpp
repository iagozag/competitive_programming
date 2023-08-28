#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, aux = 0, soma = 0; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> somas;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    //LINHAS
    for(int j = 0; j < n; j++){
        aux += v[0][j];
    }
    for(int i = 1; i < n; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            soma += v[i][j];
        }
        if(soma != aux){
            cout << "-1" << "\n";
            return(1);
        }
        aux = soma;
    }
    somas.push_back(soma);

    //COLUNAS
    aux = 0;
    for(int j = 0; j < n; j++){
        aux += v[j][0];
    }
    for(int i = 1; i < n; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            soma += v[j][i];
        }
        if(soma != aux){
            cout << "-1" << "\n";
            return(1);
        }
        aux = soma;
    }
    somas.push_back(soma);

    //DIAGONAIS
    soma = 0, aux = 0;
    for(int j = 0; j < n; j++){
        soma += v[j][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j++){
            aux += v[i][j];
            break;
        }
    }
    if(soma != aux){
        cout << "-1" << "\n";
        return(1);
    }
    somas.push_back(soma);

    //VERIFICA IGUALDADE
    for(int i = 1; i < somas.size(); i++){
        if(somas[0] != somas[i]){
            cout << "-1" << "\n";
            return(1);
        }
    }

    cout << somas[0] << "\n";
}