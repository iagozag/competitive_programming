#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k;
vector<vector<pair<int, int>>> g;
vector<vector<int>> dp;

void dfs(int v, int p){
	vector<int> ed;
	for(auto [w, ve]: g[v]) if(ve != p){
		dfs(ve, v);

		if(dp[ve][1]+w > dp[ve][0]) ed.emplace_back(dp[ve][1]+w-dp[ve][0]);

		dp[v][0] += dp[ve][0];
		dp[v][1] += dp[ve][0];
	}
	sort(ed.begin(), ed.end(), greater<int>());

	for(int i = 0; i < min(k-1, (int)ed.size()); i++){
		dp[v][0] += ed[i];
		dp[v][1] += ed[i];
	}

	if((int)ed.size() >= k) dp[v][0] += ed[k-1];
}

void solve(){
	cin >> n >> k;

	dp = vector<vector<int>>(n, vector<int>(2));
	g = vector<vector<pair<int, int>>>(n);

	for(int i = 0; i < n-1; i++){
		int a, b, w; cin >> a >> b >> w; --a, --b;
		g[a].emplace_back(w, b), g[b].emplace_back(w, a);
	}

	dfs(0, -1);
	cout << dp[0][0] << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
