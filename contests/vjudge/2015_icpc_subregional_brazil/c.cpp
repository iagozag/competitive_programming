#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

int32_t main(){ _
    int n, k;
    while(cin >> n >> k){
        if(n == k) cout << n << endl;
        else {
            cout  << max(n, k) << endl;
        }
    }
    
    exit(0);
}