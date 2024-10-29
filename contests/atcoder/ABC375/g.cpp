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
vector<vector<pair<int, int>>> g2;

void dijkstra(int s, vector<ll>& dist){
	dist = vector<ll>(n, LINF), dist[s] = 0; vector<bool> vis(n);
	priority_queue<pair<ll, int>> pq; pq.push({0, s});
	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop(), w *= -1;
		if(vis[v]) continue;

		vis[v] = 1;
		for(auto [ve, ww]: g[v]) if(dist[ve] > w+ww) dist[ve] = w+ww, pq.push({-w-ww, ve});
	}
}

vector<int> ans, tin, low;
vector<bool> vis;
int t = 0;

void dfs(int v, int p = -1){
	vis[v] = 1;
	tin[v] = low[v] = t++;
	for(auto [ve, idx]: g2[v]) if(ve != p){
		if(vis[ve]) low[v] = min(low[v], tin[ve]);
		else{
			dfs(ve, v);	
			low[v] = min(low[v], low[ve]);
			if(low[ve] > tin[v]) ans[idx] = 1;
		}
	}
}

void solve(){
	cin >> n >> m; vector<tuple<int, int, ll>> edges(m);
	g.resize(n), g2.resize(n);
	for(int i = 0; i < m; i++){
		int a, b; ll w; cin >> a >> b >> w; --a, --b;
		g[a].emplace_back(b, w), g[b].emplace_back(a, w);
		edges[i] = {a, b, w};
	}

	vector<ll> d1, d2;
	dijkstra(0, d1), dijkstra(n-1, d2);
	for(int i = 0; i < m; i++){
		auto [a, b, w] = edges[i];
		if(d1[a]+w+d2[b] == d1[n-1] or d1[b]+w+d2[a] == d1[n-1]) g2[a].emplace_back(b, i), g2[b].emplace_back(a, i);
	}

	ans = vector<int>(m), vis = vector<bool>(n), tin = low = vector<int>(n, -1);
	for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);

	for(auto x: ans) cout << (x ? "Yes" : "No") << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
