#include<bits/stdc++.h>
using namespace std;
    
int cme_verify(int number){
    if(number == 2) return 2;
    if(number % 2 == 0) return 0;
    return 1;
}

int main () {
    int n, matches, answer; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> matches;
        
        answer = cme_verify(matches);
        cout << answer << "\n";
    }
}  
