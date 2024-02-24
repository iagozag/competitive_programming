#include <bits/stdc++.h>

using namespace std;

int main(){
    
    
    long long result = 7290;
    
    int n; cin >> n;
    int count = 0;
    int i = 4;
    while(i < n){
        while(result%10 == 0 && i == 19){
            result /= 10;
            count++;
        }
        result *= 9;
        i++;
    }
    
    
    string r = to_string(result);
    while(count--){
        r+= '0';
    }
    cout << r << endl;
    

    return 0;
}
