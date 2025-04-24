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
	vector<vector<int>> g(n+1); set<pair<int, int>> edges;
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b;
		edges.insert({a, b}), edges.insert({b, a});
		g[a].emplace_back(b), g[b].emplace_back(a);
	}

	vector<vector<int>> st(2);

	auto dfs = [&](auto&& self, int v, int p, int id) -> void{
		st[id].emplace_back(v);
		for(auto ve: g[v]) if(ve != p) self(self, ve, v, !id);
	};

	dfs(dfs, 1, -1, 0);

	set<pair<int, int>> can;
	for(int i = 0; i < (int)st[0].size(); i++){
		for(int j = 0; j < (int)st[1].size(); j++){
			pair<int, int> ed = {st[0][i], st[1][j]}, edr = {st[1][j], st[0][i]};
			if(!edges.count(ed) and !edges.count(edr))
				can.insert(ed), can.insert(edr);
		}
	}

	int f = 0;
	if((can.size()/2)&1) f = 1;

	cout << (f ? "First" : "Second") << endl;

	int a, b;
	while(can.size()){
		if(f){
			a = (*can.begin()).first, b = (*can.begin()).second;
			cout << a << ' ' << b << endl;
		}
		else cin >> a >> b;

		can.erase({a, b}), can.erase({b, a}), f = !f;
	}
	cin >> a >> b;
}

int32_t main(){
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
