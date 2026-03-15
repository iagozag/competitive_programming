#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int n, m, st = -1, endd = -1;
vector<vector<int>> g(MAX);
vector<int> par(MAX, -1), vis(MAX);

bool dfs(int v, int p){
	vis[v] = 1;
	for(auto ve: g[v]) if(ve != p){
		if(vis[ve]){
			st = ve, endd = v;
			return true;
		}
		par[ve] = v;
		if(dfs(ve, v)) return true;
	}
	return false;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

	for(int i = 0; i < n; i++) if(!vis[i] and dfs(i, -1)) break;

	if(st == -1){ cout << "IMPOSSIBLE" << endl; return; }

	vector<int> ans = {st+1};
	int cur = endd;
	while(cur != st){
		ans.emplace_back(cur+1);
		cur = par[cur];
	}
	ans.emplace_back(st+1);

	cout << ans.size() << endl;
	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


