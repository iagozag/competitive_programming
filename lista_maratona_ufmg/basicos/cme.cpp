#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, matches; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> matches;
        cout << (matches == 2 ? 2 : matches%2 == 1) << endl;
    }
}  
