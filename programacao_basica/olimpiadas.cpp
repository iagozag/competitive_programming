#include<bits/stdc++.h>
using namespace std;

struct Pais{
    int id, med[3] = {0, 0, 0};
};

bool compara_medalhas(Pais a, Pais b){
    if(a.med[0] != b.med[0]) return a.med[0] > b.med[0];
    if(a.med[1] != b.med[1]) return a.med[1] > b.med[1];
    if(a.med[2] != b.med[2]) return a.med[2] > b.med[2];
    return(a.id < b.id);
}

int main(){
    int m, n, o, p, b; cin >> m >> n;
    Pais pais[m];

    for(int i = 0; i < m; i++){
        pais[i].id = i+1;
    }

    for(int i = 0; i < n; i++){
        cin >> o >> p >> b;
        pais[o-1].med[0]++;
        pais[p-1].med[1]++;
        pais[b-1].med[2]++;
    }
    sort(pais, pais+m, compara_medalhas);
    
    for(int i = 0; i < m; i++){
        cout << pais[i].id << " ";
    }
}