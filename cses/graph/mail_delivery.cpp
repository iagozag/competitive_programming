#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b, i), g[b].emplace_back(a, i);
	}

	for(int i = 0; i < n; i++) if((int)g[i].size()&1){ cout << "IMPOSSIBLE" << endl; return; }

	vector<int> ans, vis(m);
	auto dfs = [&](auto&& self, int v) -> void {
		while(!g[v].empty()){
			auto [ve, idx] = g[v].back(); g[v].pop_back();
			if(!vis[idx]){
				vis[idx] = 1;
				self(self, ve);
			}
		}
		ans.emplace_back(v);
	};

	dfs(dfs, 0);
	reverse(ans.begin(), ans.end());

	if(*min_element(vis.begin(), vis.end()) == 0){ cout << "IMPOSSIBLE" << endl; return; }

	for(auto x: ans) cout << x+1 << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
