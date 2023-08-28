#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t = 0; cin >> n;
    int v[n], r[n];

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    for(int i = 1; i <= n; i++){
        if(i == 1) r[i] = v[i] + v[i+1];
        else if(i == n) r[i] = v[i-1] + v[i];
        else r[i] = v[i-1] + v[i] + v[i+1];
    }

    for(int i = 1; i <= n; i++){
        cout << r[i];
    }
}