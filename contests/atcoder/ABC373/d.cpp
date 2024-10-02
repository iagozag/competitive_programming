#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vector<pair<int, int>>> g;
vector<ll> c; vector<int> vis;

void dfs(int v){
    vis[v] = 1;
    for(auto [ve, w]: g[v]) if(!vis[ve]){
        c[ve] = c[v]+w;
        dfs(ve);
    }
}

void solve(){
    cin >> n >> m; g = vector<vector<pair<int, int>>>(n);
    for(int i = 0; i < m; i++){
        int a, b; ll w; cin >> a >> b >> w; --a, --b, g[a].emplace_back(b, w), g[b].emplace_back(a, -w); 
    }

    c = vector<ll>(n), vis = vector<int>(n);
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);

    for(auto x: c) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

