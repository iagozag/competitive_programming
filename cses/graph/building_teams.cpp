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

	vector<int> ans(n, -1);
	auto dfs = [&](auto&& self, int v, int c) -> void {
		ans[v] = c;
		for(auto ve: g[v]) if(ans[ve] == -1) self(self, ve, ans[v]^1^2);
	};

	for(int i = 0; i < n; i++) if(ans[i] == -1){
		dfs(dfs, i, 1);
	}

	for(int i = 0; i < n; i++){
		for(auto ve: g[i]) if(ans[i] == ans[ve]){ cout << "IMPOSSIBLE" << endl; return; }
	}

	for(auto x: ans) cout << x << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
