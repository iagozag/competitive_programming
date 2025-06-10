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
		g[a].emplace_back(b);
	}

	vector<int> color(n), par(n, -1); int st = -1, end = -1;
	auto dfs = [&](auto&& self, int v) -> bool {
		color[v] = 1;
		for(auto ve: g[v]){
			if(color[ve] == 1){
				st = ve, end = v;
				return true;
			}
			else if(color[ve] == 0){
				par[ve] = v;
				if(self(self, ve)) return true;
			}
		}

		color[v] = 2;

		return false;
	};

	for(int i = 0; i < n; i++) if(color[i] == 0 and dfs(dfs, i)){
		vector<int> ans = {st};
		while(end != st){
			ans.emplace_back(end), end = par[end];
		}
		ans.emplace_back(st);
		reverse(ans.begin(), ans.end());
		
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
