#include<bits/stdc++.h>
using namespace std;

struct Piloto{
    int id, pontos;
    vector<int> colocacoes;
};

void imprime_maiores(Piloto *a, int size){
    int max = 0;

    for (int i = 0; i < size; i++)
        if(a[i].pontos > max) max = a[i].pontos;
    
    bool f = true;
    for (int i = 0; i < size; i++){
        if(a[i].pontos == max){
            if(f){
                printf("%d", i + 1);
                f = false;
            }else printf(" %d", i + 1);
        }
    }
    cout << "\n";
}

int main(){
    int g, p, c, s, k;

    while(cin >> g >> p && g || p){
        Piloto pilotos[p];
        for(int i = 0; i < p; i++){
            pilotos[i].id = i+1;
        }

        for(int i = 0; i < g; i++){
            for(int j = 0; j < p; j++){
                cin >> c;
                pilotos[j].colocacoes.push_back(c);
            }
        }

        cin >> s;
        for(int i = 0; i < s; i++){
            cin >> k;
            vector<int> score(k);

            for(int j = 0; j < k; j++)
                cin >> score[j];

            for(int l = 0; l < p; l++){
                pilotos[l].pontos = 0;
                for(int m = 0; m < g; m++)
                    if (pilotos[l].colocacoes[m] <= k)
                        pilotos[l].pontos += score[pilotos[l].colocacoes[m] - 1];
            }
            imprime_maiores(pilotos, p);
        }
    }
}