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
		g[a].emplace_back(b);
	}

	vector<int> vis(n);
	auto dfs = [&](auto&& self, int v) -> void {
		vis[v] = 1;
		for(auto ve: g[v]) if(!vis[ve]) self(self, ve);
	};


	vector<int> dp(n, LINF), par(n, -1);
	for(int i = 0; i < n; i++) if(!vis[i]) dp[i] = 0, dfs(dfs, i);
	int st = -1;
	for(int k = 0; k < n; k++){
		st = -1;
		for(auto [a, b, w]: edges) if(dp[a] < LINF and dp[b] > dp[a]+w) 
			dp[b] = max(-LINF, dp[a]+w), par[b] = a, st = b;
	}

	if(st != -1){
		cout << "YES" << endl;

		for(int i = 0; i < n; i++) st = par[st];

		vector<int> ans;
		int end = st;
		while(true){
			ans.emplace_back(st);
			st = par[st];
			if(st == end and ans.size() > 1) break;
		}
		if(ans.back() != st) ans.emplace_back(st);
		reverse(ans.begin(), ans.end());

		for(auto x: ans) cout << x+1 << ' ';
		cout << endl;
	} else cout << "NO" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
