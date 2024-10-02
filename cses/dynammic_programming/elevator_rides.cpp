#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void ckmin(pair<ll, ll>& a, pair<ll, ll> b){
    if(b.first < a.first or (b.first == a.first and b.second < a.second)) a = b;
}

void solve(){
    int n; ll x; cin >> n >> x;
    vector<ll> v(n); for(auto& k: v) cin >> k;

    vector<pair<ll, ll>> dp(1<<n, {LINF, LINF}); dp[0] = {1, 0};
    for(int i = 1; i < (1<<n); i++){
        for(int j = 0; j < n; j++) if(i&(1<<j)){
            if(dp[i-(1<<j)].second+v[j] <= x) ckmin(dp[i], {dp[i-(1<<j)].first, dp[i-(1<<j)].second+v[j]});
            else ckmin(dp[i], {dp[i-(1<<j)].first+1, v[j]});
        }
    }
    cout << dp[(1<<n)-1].first << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
