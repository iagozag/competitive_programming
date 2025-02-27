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
	int n, k; cin >> n >> k;
	vector<int> cnt(n); vector<vector<int>> g(n);
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a);
	}

	auto dfs = [&](auto&& self, int v, int can, int h, int p) -> void{
		int c = 1;
		if(can and !cnt[h]) cnt[h] = 1, c = 0;

		for(auto ve: g[v]) if(ve != p){
			self(self, ve, c, h+1, v);
		}
	};

	dfs(dfs, 0, 1, 0, -1);

	int ans = 0;
	for(auto x: cnt) ans += x;

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
