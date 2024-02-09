#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n; cin >> n;
    
    int total = 0;
    
    while(n--){
        int t; cin >> t;
        int tam = 10; int b = 4;
        while(t--){
            int aux = b;
            while(aux--){
              if(tam > 1) tam--;
              else total++;
            }
            if(b > 1) b--;
        }
    }

    cout << total << endl;

    return 0;
}
