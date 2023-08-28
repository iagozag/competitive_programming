#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, soma = 0; cin >> n;
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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            soma = 0;
            for(int k = 0; k < n; k++){
                soma += v[i][k] + v[k][j];
            }
            soma -= 2 * v[i][j];
            somas.push_back(soma);
        }
    }
    cout << *max_element(somas.begin(), somas.end()) << endl;
}