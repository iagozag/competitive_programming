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
	int Q; cin >> Q;
	vector<int> queries;
	vector<vector<int>> g(MAX);
	int k = 1;
	for(int i = 0; i < Q; i++){
		int a, b; cin >> a >> b; --a, --b;
		if(a == 0){
			g[b].emplace_back(k++);
		} else queries.emplace_back(b);
	}

	vector<int> alive(k, 1), id(k), rev(k); int j = 0;
	auto dfs = [&](auto&& self, int v, int p) -> void {
		rev[j] = v, id[v] = j++;
		for(auto ve: g[v]) if(ve != p) self(self, ve, v);
	};

	dfs(dfs, 0, -1);

	for(auto q: queries)  alive[id[q]] = 0;
	int mi = INF;
	for(int i = 0; i < k; i++) if(alive[i]){ mi = i; break; }

	vector<int> ans;
	for(int i = (int)queries.size()-1; i >= 0; i--){
		auto u = queries[i];
		ans.emplace_back(rev[mi]);
		mi = min(mi, id[u]);
	}

	reverse(ans.begin(), ans.end());
	for(auto x: ans) cout << x+1 << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
