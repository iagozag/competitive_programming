#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    
    int n; cin >> n;
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(isPrime(i)) count++;
    }

    cout << count << endl;

    return 0;
}
