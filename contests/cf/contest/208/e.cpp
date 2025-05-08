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
	int n; cin >> n;
	vector<vector<int>> g(n);

	vector<vector<int>> dp(n, vector<int>(32, -1));
	for(int i = 0; i < n; i++){
		int p; cin >> p; --p;
		if(p != -1) dp[i][0] = p, g[p].emplace_back(i);
	}

	for(int i = 1; i < 32; i++)
		for(int j = 0; j < n; j++)
			dp[j][i] = (dp[j][i-1] != -1 ? dp[dp[j][i-1]][i-1] : -1);

	auto kth = [&](int i, int k) -> int {
		int j = i;
		for(int l = 0; l < 32 and j != -1; l++) if((k>>l)&1)
			j = dp[j][l];

		return j;
	};

	vector<vector<int>> idx(n);
	vector<int> pos(n, -1), child(n), depth(n);
	auto dfs = [&](auto&& self, int i, int& j, int d) -> void {
		pos[i] = j;
		depth[i] = d;
		idx[d].emplace_back(j++);
		child[i] = 1;
		for(auto ve: g[i]){
			self(self, ve, j, d+1);
			child[i] += child[ve];
		}
	};

	int j = 0;
	for(int i = 0; i < n; i++) if(pos[i] == -1)
		dfs(dfs, i, j, 0);

	int Q; cin >> Q;
	for(int q = 0; q < Q; q++){
		int v, k; cin >> v >> k; --v;
		int ve = kth(v, k), de = depth[v];
		if(ve == -1){ cout << 0 << ' '; continue; }

		int b = pos[ve], e = pos[ve]+child[ve]-1;
		int lb = lower_bound(idx[de].begin(), idx[de].end(), b)-idx[de].begin(), 
			ub = upper_bound(idx[de].begin(), idx[de].end(), e)-idx[de].begin();

		cout << ub-lb-1 << ' ';
	}

	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
