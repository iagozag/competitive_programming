#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, sum = 0; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;

        if(a == b) cout << 0 << "\n";
        else if(a < b){
            if((b-a) % 2 == 0) cout << 2 << "\n";
            else cout << 1 << "\n";
        } else{
            if((a-b) % 2 == 0) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
    }
}
