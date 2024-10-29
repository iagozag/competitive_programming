#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vector<int>> g;
vector<int> par, dist, id;

void dfs(int v, int p){
   	for(auto ve: g[v]) if(ve != p) dist[ve] = dist[v]+1, par[ve] = v, dfs(ve, v);
}

void solve(){
	int n; cin >> n;
    g = vector<vector<int>>(n);
	vector<pair<int, int>> pairs(n/2, {-1, -1});
	for(int i = 0; i < n; i++){
		int a; cin >> a; --a;
		if(pairs[a].first == -1) pairs[a].first = i;
		else pairs[a].second = i;
	}

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; --a, --b;
        g[a].emplace_back(b), g[b].emplace_back(a);
    }

	par = vector<int>(n), dist = vector<int>(n);
	dfs(0, -1);

	int LOG = 0; while((1<<LOG) <= n) LOG++;

	vector<vector<int>> dp(n, vector<int>(LOG));
	for(int i = 0; i < n; i++) dp[i][0] = par[i];
	for(int p = 1; p < LOG; p++) for(int v = 0; v < n; v++) dp[v][p] = dp[dp[v][p-1]][p-1];

	ll tot = 0;
	for(int i = 0; i < n/2; i++){
		int a = pairs[i].first, b = pairs[i].second; ll ans = 0;
		if(dist[a] > dist[b]) swap(a, b);

		int need = dist[b]-dist[a];
		for(int j = LOG-1; j >= 0; j--) if(need&(1<<j)) ans += (1<<j), b = dp[b][j];

		if(a == b){ tot += ans; continue; }

		for(int j = LOG-1; j >= 0; j--) if(dp[a][j] != dp[b][j]) ans += (1<<(j+1)), a = dp[a][j], b = dp[b][j];
		tot += ans+2;
	}
	cout << tot << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

