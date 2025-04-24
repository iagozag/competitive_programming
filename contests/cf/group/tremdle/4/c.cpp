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
	vector<vector<int>> g(n); vector<int> cnt(n);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), cnt[b]++;
	}

	vector<int> color(n); bool can = 1;
	auto dfs = [&](auto&& self, int v) -> void{
		if(!can) return;
		color[v] = 1;
		for(auto ve: g[v]){
			if(color[ve] == 1){ can = 0; return; }
			else if(color[ve] == 0){
				self(self, ve);
			}
		}

		color[v] = 2;
	};

	for(int i = 0; i < n; i++) if(!color[i]) dfs(dfs, i);

	if(!can){ cout << -1 << endl; return; }

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++) if(cnt[i] == 0) pq.push(i);

	vector<int> ans;
	while(!pq.empty()){
		auto v = pq.top(); pq.pop();

		ans.emplace_back(v);
		for(auto ve: g[v]){
			cnt[ve]--;
			if(cnt[ve] == 0) pq.push(ve);
		}
	}

	for(auto x: ans) cout << x+1 << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
