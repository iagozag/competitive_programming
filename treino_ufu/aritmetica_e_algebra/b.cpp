#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    
    while(n--){
        long long t, i , a; cin >> t >> i >> a;
        long long count = 0;
        long long aux = i, soma = 0;
        while(soma < t){
            soma += aux;
            aux = aux + a;
            count++;
        }
        cout << count << endl;
    }

    return 0;
}
