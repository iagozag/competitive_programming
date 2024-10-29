#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

void sum(int& a, int b){
    a += b, a %= MOD;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    if(!m){ cout << 1 << endl; return; }

    set<int> s; vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; --a, --b;
        s.insert(a), s.insert(b), edges.emplace_back(a, b);
    }
    s.insert(0);
    int v = 0; vector<int> hash(m*2+1); map<int, int> mp;
    for(auto& x: s) mp[x] = v, hash[v++] = x;

    vector<vector<pair<int, int>>> g(v);
    for(int i = 0; i < v; i++){
        if(hash[(i+1)%v] > hash[i])
            g[i].emplace_back((i+1)%v, hash[(i+1)%v]-hash[i]);
        else
            g[i].emplace_back((i+1)%v, n-hash[i]+hash[(i+1)%v]);
    }
    for(auto [u, ve]: edges) g[mp[u]].emplace_back(mp[ve], 1);

    vector<vector<int>> dp(v, vector<int>(k+1)); dp[0][0] = 1;
    for(int i = 0; i < k; i++) for(int j = 0; j < v; j++){
        for(auto [ve, w]: g[j]) sum(dp[ve][min(k, i+w)], dp[j][i]);
    }

    int ans = 0;
    for(int i = 0; i < v; i++) sum(ans, dp[i][k]);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
