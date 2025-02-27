#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<int> a;
vector<vector<int>> g;
vector<vector<int>> dp(n, vector<int>(20));

void dfs(int u, int p){
	for(int i = 1; i < 20; i++) dp[u][i] = a[u]*i;

	for(auto v: g[u]) if(v != p){
		dfs(v, u);

		for(int i = 1; i < 20; i++){
			int mi = LINF;
			for(int j = 1; j < 20; j++) if(i != j) mi = min(mi, dp[v][j]);
			dp[u][i] += mi;
		}
	}
}

void solve(){
	cin >> n;
	g = vector<vector<int>>(n), a = vector<int>(n), dp = vector<vector<int>>(n, vector<int>(20));
	for(auto& x: a) cin >> x;
	for(int i = 0; i < n-1; i++){ int x, y; cin >> x >> y; --x, --y; g[x].emplace_back(y), g[y].emplace_back(x); }

	dfs(0, -1);

	int mi = LINF;
	for(int i = 1; i < 20; i++) mi = min(mi, dp[0][i]);
	cout << mi << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
