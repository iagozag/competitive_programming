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
	vector<tuple<int, int, int>> edges;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w; --a, --b;
		edges.emplace_back(a, b, w);
		g[b].emplace_back(a);
	}

	vector<int> vis(n);
	auto dfs = [&](auto&& self, int v) -> void {
		vis[v] = 1;
		for(auto ve: g[v]) if(!vis[ve]) self(self, ve);
	};

	dfs(dfs, n-1);

	vector<int> dp(n, -LINF); dp[0] = 0;
	int cyc = 0;
	for(int k = 0; k < n; k++){
		cyc = 0;
		for(auto [a, b, w]: edges) if(dp[a] > -LINF and dp[b] < dp[a]+w) 
			dp[b] = dp[a]+w, cyc |= vis[a] | vis[b];
	}

	if(cyc){ cout << -1 << endl; return; }

	cout << dp[n-1] << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
