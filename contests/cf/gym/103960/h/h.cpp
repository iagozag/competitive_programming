#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vector<int>> g, g_t;
vector<int> vis, sorted, id;

void toposort(int v){
	vis[v] = 1;
	for(auto ve: g[v]) if(!vis[ve]) toposort(ve);
	sorted.emplace_back(v);
}

void dfs(int v, int k){
	id[v] = k, vis[v] = 1;
	for(auto ve: g_t[v]) if(!vis[ve]) dfs(ve, k);
}

void solve(){
	cin >> n >> m; g.resize(n), g_t.resize(n); vector<pair<int, int>> edges;
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g_t[b].emplace_back(a), edges.emplace_back(a, b); }
	
	vis = vector<int>(n);
	for(int i = 0; i < n; i++) if(!vis[i]) toposort(i);
	reverse(sorted.begin(), sorted.end());

	vis = id = vector<int>(n); iota(id.begin(), id.end(), 0); int k = 0;
	for(auto x: sorted) if(!vis[x]) dfs(x, k++);

	if(k == 1){ cout << 0 << endl; return; }

	g = g_t = vector<vector<int>>(k);
	for(auto [a, b]: edges) if(id[a] != id[b]) g[id[a]].emplace_back(id[b]), g_t[id[b]].emplace_back(id[a]);

	int ans = 0;
	for(int i = 0; i < k; i++) ans += !g[i].size() + !g_t[i].size();
	cout << (ans+1)/2 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
