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
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}

	vector<pair<int, int>> ans;
	
	vector<int> vis(n); bool can = 0;
	auto dfs = [&](auto&& self, int v, int d) -> void {
		vis[v] = 1;

		for(auto ve: g[v]) if(!vis[ve]){
			if(g[v].size() == 2 and !can){
				can = 1;
				if(!d) ans.emplace_back(v, ve);
				else ans.emplace_back(ve, v);
				self(self, ve, d);
			} else{
				if(d) ans.emplace_back(v, ve);
				else ans.emplace_back(ve, v);
				self(self, ve, !d);
			}
		}
	};

	dfs(dfs, 0, 0);

	if(can){
		cout << "YES" << endl;
		for(auto [a, b]: ans) cout << a+1 << ' ' << b+1 << endl;
	}
	else cout << "NO" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
