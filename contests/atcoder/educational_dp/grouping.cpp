#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<vector<ll>> mat(n, vector<ll>(n));
    for(auto& x: mat) for(auto& y: x) cin >> y;

    vector<ll> sums(1<<n, -1); sums[0] = 0;
    for(int i = 0; i < (1<<n); i++) for(int j = 0; j < n; j++) if(!(i&(1<<j)) and sums[i|(1<<j)] == -1){
        sums[i|(1<<j)] = sums[i];
        for(int k = 0; k < n; k++) if(i&(1<<k)) sums[i|(1<<j)] += mat[j][k];
    }

    vector<ll> dp(1<<n);
    for(int i = 0; i < (1<<n); i++) for(int j = i; j; j = (j-1)&i) 
        dp[i] = max(dp[i], sums[j]+dp[i-j]);

    cout << dp[(1<<n)-1] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
