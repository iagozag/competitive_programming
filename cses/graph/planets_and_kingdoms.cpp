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
	vector<vector<int>> g(n), gt(n);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), gt[b].emplace_back(a);
	}

	vector<int> ord, vis(n), king(n);
	auto dfs = [&](auto&& self, bool rev, int v, int k = -1) -> void{
		vis[v] = 1;
		if(rev) king[v] = k;
		for(auto ve: (rev ? gt[v] : g[v])) if(!vis[ve]) self(self, rev, ve, k);
		if(!rev) ord.emplace_back(v);
	};
	for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, 0, i);
	reverse(ord.begin(), ord.end());

	int cnt = 0; vis = vector<int>(n);
	for(auto i: ord) if(!vis[i]){
		dfs(dfs, 1, i, cnt), cnt++;
	}

	cout << cnt << endl;
	for(auto x: king) cout << x+1 << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
