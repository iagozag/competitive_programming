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
    vector<vector<ll>> v(n, vector<ll>(3)); set<ll> s;
    for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1] >> v[i][2], s.insert(v[i][0]), s.insert(v[i][1]);
    map<ll, ll> mp; ll k = 1;
    for(auto x: s) mp[x] = k++;

    vector<vector<pair<ll, ll>>> ends(k);
    for(int i = 0; i < n; i++){
        ends[mp[v[i][1]]].emplace_back(mp[v[i][0]], v[i][2]);
    }

    vector<ll> dp(k+1);
    for(int i = 1; i < k; i++){
        dp[i+1] = dp[i];
        for(auto [x, p]: ends[i]) dp[i+1] = max(dp[i+1], dp[x]+p); 
    }
    cout << dp[k] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
