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
    
    int a, b; cin >> a >> b;
    
    for(int i = a; i <= b; i++){
        int num = 0, aux = i;
        while(aux > 0){
          num += aux%10;
          aux = aux/10;
        }
        if(isPrime(i) && isPrime(num)) cout << i << endl;
    }
    

    return 0;
}
