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
	const int B = sqrt(m)+1;

	vector<vector<int>> g(n), g_big(n);
	for(int i = 0; i < m; i++){ int u, v; cin >> u >> v; --u, --v; g[u].emplace_back(v), g[v].emplace_back(u); }

	vector<int> big(n);
	for(int i = 0; i < n; i++) if((int)g[i].size() > B) big[i] = 1;
	for(int i = 0; i < n; i++) for(auto ve: g[i]) if(big[ve]) g_big[i].emplace_back(ve);

	vector<int> ans(n), upd(n, -1); iota(ans.begin(), ans.end(), 0);
	vector<pair<int, int>> big_upd(n, {-1, -1});

	for(int i = 0; i < q; i++){
		int x; cin >> x; --x;

		int ma = -1, color = -1;
		for(auto v: g_big[x]) if(ma < big_upd[v].first) ma = big_upd[v].first, color = big_upd[v].second;
		if(upd[x] < ma) ans[x] = color;

		if(big[x]){ big_upd[x] = {i, ans[x]}; continue; }

		for(auto v: g[x]) ans[v] = ans[x], upd[v] = i;
		upd[x] = i;
	}

	for(int x = 0; x < n; x++){
		int ma = -1, color = -1;
		for(auto v: g_big[x]) if(ma < big_upd[v].first) ma = big_upd[v].first, color = big_upd[v].second;
		if(upd[x] < ma) ans[x] = color;
	}

	for(auto x: ans) cout << x+1 << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
