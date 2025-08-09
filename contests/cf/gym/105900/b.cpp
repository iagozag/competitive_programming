#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

const int MOD = 1e9 + 7;

ll exp(int n, int e){
    ll ans = 1; 
    while(e > 0){
        if(e%2==1) ans = ans * n % MOD;
        n = n*n % MOD;
        e/=2;
    }

    return ans;
}

int32_t main(){ _
   int n, k; cin >> n >> k;
   int ans = 0;
   for(int i = 0; i < 31; i++) if(k&(1<<i)) ans += exp(n, i), ans %= MOD;
   cout << ans << endl;
}