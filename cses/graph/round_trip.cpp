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
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}

	vector<int> vis(n), par(n); int st = -1, end = -1;
	auto dfs = [&](auto&& self, int v, int p) -> bool {
		vis[v] = 1;
		for(auto ve: g[v]) if(ve != p){
			if(vis[ve]){
				st = ve, end = v;
				return true;
			}
			else{
				par[ve] = v;
				if(self(self, ve, v)) return true;
			}
		}

		return false;
	};

	for(int i = 0; i < n; i++) if(!vis[i] and dfs(dfs, i, -1)){
		vector<int> ans = {st};
		while(end != st){
			ans.emplace_back(end), end = par[end];
		}
		ans.emplace_back(st);
		
		cout << ans.size() << endl;
		for(auto x: ans) cout << x+1 << ' ';
		cout << endl;

		return;
	}
	cout << "IMPOSSIBLE" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
