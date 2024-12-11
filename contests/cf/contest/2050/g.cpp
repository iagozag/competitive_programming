#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<vector<int>> g;
vector<int> dp, dp2;

int dfs(int v, int p){
	vector<int> x;
	for(auto ve: g[v]) if(ve != p)
		x.emplace_back(dfs(ve, v));
	sort(x.begin(), x.end(), greater<int>());

	if(x.size() > 1) dp2[v] = g[v].size()-2+x[0]+x[1];

	return dp[v] = (x.size() ? x[0] : 0)+g[v].size()-1;
}

void solve(){
	int n; cin >> n;
	g = vector<vector<int>>(n), dp = dp2 = vector<int>(n);
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}

	dfs(0, -1);

	int ans = 1; 
	for(int i = 0; i < n; i++) ans = max({ans, dp[i], dp2[i], (int)g[i].size()});

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
