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
		g[b].emplace_back(a);
	}

	vector<int> memo(n, -1); memo[0] = 1;
	auto dp = [&](auto&& self, int v) -> int {
		if(memo[v] != -1) return memo[v];
		memo[v] = 0;
		for(auto ve: g[v]){
			memo[v] = (memo[v]+self(self, ve))%MOD;
		}
		return memo[v];
	};

	cout << dp(dp, n-1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
