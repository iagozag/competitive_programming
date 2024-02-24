#include <bits/stdc++.h>

using namespace std;

long long int invert(long long int n){
    string num = to_string(n);
    string p = "";
    for(int i = num.size() - 1; i >= 0; i--){
        p+= num[i];
    }
    
    return stoll(p); 
}

bool palindromo(long long int n){
    long long int p = invert(n);
    if(p == n) return true;
    else return false;
}

int main(){
    
    long long int n; 
    cin >> n;
    bool done = true;
    for(int i= 0; i < 20; i++){
        if(palindromo(n + invert(n))){
            done = false;
            break;
        }
        n += invert(n);
    }
    
    if(done) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
