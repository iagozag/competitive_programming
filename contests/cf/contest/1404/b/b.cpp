#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, a, b, da, db;
vector<vector<int>> g;
vector<int> dist;

void dfs(int v){
    for(auto& ve: g[v]) if(dist[ve] == -1) dist[ve] = dist[v]+1, dfs(ve);
}

void solve(){
    cin >> n >> a >> b >> da >> db; --a, --b;
    g = vector<vector<int>>(n);
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y; --x, --y;
        g[x].emplace_back(y), g[y].emplace_back(x);
    }
    dist = vector<int>(n, -1);
    dist[a] = 0, dfs(a);
    if(dist[b] <= da or db <= 2*da){ cout << "Alice" << endl; return; }

    int idx = a;
    for(int i = 0; i < n; i++) if(dist[idx] < dist[i]) idx = i;

    dist = vector<int>(n, -1); dist[idx] = 0; dfs(idx);
    for(int i = 0; i < n; i++) if(dist[idx] < dist[i]) idx = i;

    if(dist[idx] <= 2*da) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
