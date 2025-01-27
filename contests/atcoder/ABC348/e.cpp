#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 5ULL*1e18;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, sum = 0;
vector<vector<int>> g;
vector<pair<int, int>> dp;
vector<int> c, f;

void dfs(int v, int p){
	dp[v].first = c[v];
	for(auto ve: g[v]) if(ve != p){
		dfs(ve, v);
		dp[v].first += dp[ve].first;
		dp[v].second += dp[ve].first+dp[ve].second;
	}
}

void dfs2(int v, int p){
	for(auto ve: g[v]) if(ve != p){
		f[ve] = f[v]+dp[0].first-2*dp[ve].first;
		dfs2(ve, v);
	}
}

void solve(){
	cin >> n; g.resize(n), c.resize(n), f.resize(n), dp.resize(n);
	for(int i = 0; i < n-1; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }
	for(int i = 0; i < n; i++) cin >> c[i], dp[i].first = c[i];

	dfs(0, -1);

	f[0] = dp[0].second;

	dfs2(0, -1);

	int ans = LINF;
	for(int i = 0; i < n; i++) ans = min(ans, f[i]);
	cout << ans << endl;

}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
