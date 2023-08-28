#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, p, q; cin >> n >> p;
    char c; cin >> c;
    cin >> q;

    if(c == '*'){
        if(p * q > n) cout << "OVERFLOW";
        else cout << "OK";
    }
    else if(c == '+'){
        if(p + q > n) cout << "OVERFLOW";
        else cout << "OK";
    }
}