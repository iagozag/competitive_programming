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
	vector<vector<int>> g(n); set<pair<int, int>> edges;
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}

	int tot = n, qnt = 0; set<int> S; vector<int> can(n, 1);
	auto dfs = [&](auto&& self, int v, int p) -> void{
		if(qnt >= tot/2) return;

		S.insert(v);

		if(can[v] and qnt < tot/2) qnt++;

		for(auto ve: g[v]) if(ve != p) self(self, ve, v);
	};

	for(int k = 0; k < 10; k++){
		S = set<int>(); qnt = 0;
		dfs(dfs, 0, -1);

		if(S.size() == 0) break;

		cout << "? " << S.size() << ' ';
		for(auto x: S) cout << x+1 << ' ';
		cout << endl;

		int op; cin >> op;
		if(op){
			for(int i = 0; i < n; i++) if(can[i] and !S.count(i)) can[i] = 0, tot--;
		} else{
			for(auto x: S) tot -= can[x], can[x] = 0;
		}
	}
	
	for(int i = 0; i < n; i++) if(can[i]){ cout << "! " << i+1 << endl; return; }
}

int32_t main(){ // _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
