#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<vector<int>> dp;

void sum(int&a, int b){
	a += b, a %= MOD;
}

int dfs(int v, int mask){
	int& p = dp[v][mask];
	if(v == n-1) p = (mask == (1<<n)-1);
	if(p != -1) return p;

	p = 0;
	for(auto ve: g[v]) if(!(mask&(1<<ve)))
		sum(p, dfs(ve, mask|(1<<ve)));	

	return p;
}

void solve(){
	cin >> n >> m;
	g = vector<vector<int>>(n);
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b); }

	dp = vector<vector<int>>(n, vector<int>(1<<n, -1));
	cout << dfs(0, 1) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
