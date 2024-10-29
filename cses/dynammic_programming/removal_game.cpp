#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5000, MOD = 1e9+7;

int n;
vector<ll> v;
vector<vector<ll>> dp(MAX, vector<ll>(MAX));

void solve(){
    cin >> n;
    v = vector<ll>(n); for(auto& x: v) cin >> x;
    for(int i = 0; i < n; i++) dp[i][i] = ((n-1)&1 ? 0 : v[i]);
    for(int i = 1; i < n; i++) for(int j = 0; j < n-i; j++){
        int l = j, r = l+i; 
        if((n-(r-l+1))&1) dp[l][r] = min(dp[l+1][r], dp[l][r-1]);
        else dp[l][r] = max(v[l]+dp[l+1][r], v[r]+dp[l][r-1]);
    }
    cout << dp[0][n-1] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
