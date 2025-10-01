#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 50010, MOD = 1e9+7;

struct edge{
	int v; bool alive;
	edge(int _v, int _alive): v(_v), alive(_alive){}
};

vector<edge> g[MAX];
vector<int> g_large[MAX];
int on[MAX], ans[MAX], big[MAX];

void solve(){
	int n, m, q; cin >> n >> m >> q;
	const int B = sqrt(m+q);

	memset(on, 0, sizeof on);
	memset(ans, 0, sizeof ans);
	memset(big, 0, sizeof big);

	int o; cin >> o; for(int i = 0; i < o; i++){ int a; cin >> a; on[a-1] = 1; }

	map<pair<int, int>, int> mp;
	for(int i = 0; i < m; i++){ 
		int a, b; cin >> a >> b; --a, --b; 
		mp[{a, b}] = g[a].size(), mp[{b, a}] = g[b].size();
		g[a].emplace_back(b, 1), g[b].emplace_back(a, 1);
	}

	vector<tuple<char, int, int>> qu(q);
	for(auto& [op, u, v]: qu){
		cin >> op >> u; --u;
		if(op == 'A' or op == 'D'){
			cin >> v; --v;
			if(!mp.count({u, v})){
				mp[{u, v}] = g[u].size(), mp[{v, u}] = g[v].size();
				g[u].emplace_back(v, 0), g[v].emplace_back(u, 0);
			}
		}
	}

	for(int i = 0; i < n; i++) big[i] = (g[i].size() > B);

	for(int i = 0; i < n; i++) for(auto& [ve, alive]: g[i]) {
		if(big[i] and alive) ans[i] += on[ve];
		if(big[ve]) g_large[i].emplace_back(ve);
	}

	auto online = [&](int u) -> void{
		on[u] = 1;
		for(auto& v: g_large[u]) if(g[u][mp[{u, v}]].alive) ans[v]++;
	};

	auto offline = [&](int u) -> void{
		on[u] = 0;
		for(auto& v: g_large[u]) if(g[u][mp[{u, v}]].alive) ans[v]--;
	};

	auto add_friend = [&](int u, int v) -> void{
		g[u][mp[{u, v}]].alive = 1, g[v][mp[{v, u}]].alive = 1;
		if(big[u]) ans[u] += on[v];
		if(big[v]) ans[v] += on[u];
	};

	auto del_friend = [&](int u, int v) -> void{
		g[u][mp[{u, v}]].alive = 0, g[v][mp[{v, u}]].alive = 0;
		if(big[u]) ans[u] -= on[v];
		if(big[v]) ans[v] -= on[u];
	};

	auto count_online_friends = [&](int u) -> int{
		if(big[u]) return ans[u];

		int cnt = 0;
		for(auto& [v, alive]: g[u]) if(alive) cnt += on[v];
		return cnt;
	};

	for(auto& [op, u, v]: qu){
		switch(op){
			case 'O':
				online(u);
				break;
			case 'F':
				offline(u);
				break;
			case 'A':
				add_friend(u, v);
				break;
			case 'D':
				del_friend(u, v);
				break;
			case 'C':
				cout << count_online_friends(u) << endl;
				break;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

