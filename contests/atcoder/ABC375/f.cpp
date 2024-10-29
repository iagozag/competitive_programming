#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<tuple<int, int, ll>> edges;
	for(int i = 0; i < m; i++){
		int a, b; ll w; cin >> a >> b >> w; --a, --b; edges.emplace_back(a, b, w);
	}

	vector<bool> can(m, 1);
	vector<tuple<int, int, int>> queries;
	for(int i = 0; i < q; i++){
		int op, a, b = -1; cin >> op >> a; --a; 
		if(op == 1) can[a] = 0;
		else if(op == 2) cin >> b, --b;
		queries.emplace_back(op, a, b);
	}

	ll dp[n][n]; fill(&dp[0][0], &dp[0][0]+n*n, LINF); 
	for(int i = 0; i < n; i++) dp[i][i] = 0;
	for(int i = 0; i < m; i++) if(can[i]){
		auto [a, b, w] = edges[i];
		dp[a][b] = dp[b][a] = min(dp[a][b], w);
	}

	for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);

	vector<ll> ans;
	reverse(queries.begin(), queries.end());
	for(auto [op, a, b]: queries){
		if(op == 2) ans.emplace_back(dp[a][b]);
		else{
			auto [x, y, w] = edges[a];
			dp[x][y] = dp[y][x] = min(dp[x][y], w);	
			for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = min(dp[i][j], dp[i][x]+dp[x][j]);
			for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = min(dp[i][j], dp[i][y]+dp[y][j]);
		}
	}

	reverse(ans.begin(), ans.end());
	for(auto x: ans) cout << (x == LINF ? -1 : x) << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
