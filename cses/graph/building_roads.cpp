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
		g[a].emplace_back(b), g[b].emplace_back(a);
	}


	vector<int> comp(n, -1);
	auto dfs = [&](auto&& self, int i, int k) -> void {
		comp[i] = k;
		for(auto ve: g[i]) if(comp[ve] == -1) self(self, ve, k);
	};

	int k = 0;
	for(int i = 0; i < n; i++) if(comp[i] == -1){
		dfs(dfs, i, k), k++;
	}

	cout << k-1 << endl;
	vector<int> vis(k); vis[0] = 1;
	for(int i = 1; i < n; i++){
		if(!vis[comp[i]]) cout << 1 << ' ' << i+1 << endl, vis[comp[i]] = 1;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
