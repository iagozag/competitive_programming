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
    
    long long n; cin >> n;
    while(n--){
        int num; cin >> num;
        vector<long long> primes;
    
        for(int i = 2; i <= num; i++){
            if(isPrime(i)) primes.push_back(i);
        }
        
        bool done = false;
        for(int i = 0; i < primes.size(); i++){
            for(int j = 0; j < primes.size(); j++){
                if(primes[i] + primes[j] == num){
                    done = true;
                    break;
                }
            }
            if(done) break;
        }
        
        if(done) cout << 1 << endl;
        else cout << 0 << endl;
        
    }

    return 0;
}
