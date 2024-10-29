#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<int> can, vis, low, tin, sz;
vector<vector<pair<int, int>>> g;

ll sum(ll a, ll b){
	return a*(a-1)/2+b*(b-1)/2;
}

int t;
void dfs(int v, int p){
	vis[v] = 1;
	tin[v] = low[v] = t++;
	for(auto [ve, idx]: g[v]) if(ve != p){
		if(vis[ve]) low[v] = min(low[v], tin[ve]);
		else{
			dfs(ve, v); sz[v] += sz[ve];
			low[v] = min(low[v], low[ve]);
			if(tin[v] < low[ve]) can[idx] = 0;
		}
	}
}

void solve(){
	cin >> n >> m; g = vector<vector<pair<int, int>>>(n);

	vector<pair<int, int>> edges(m);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b, i), g[b].emplace_back(a, i), edges.emplace_back(a, b);
	}

	can = vector<int>(m, 1), vis = sz = vector<int>(n, 1);
	low = tin = vector<int>(n, -1), t = 0;
	for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, -1);

	ll ans = sum(n, 0); vis = vector<int>(n);
	for(int i = 0; i < m; i++) if(!can[i]){
		auto[a, b] = edges[i]; int comp = min(sz[a], sz[b])	;
		ans = min(ans, sum(n-comp, comp));
	}
	cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
