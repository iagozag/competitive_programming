#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

vector<int> g[MAX];
vector<int> g2[MAX];
vector<int> g3[MAX];
int vis[MAX];
set<pair<int, int>> st;

void dfs(int v, int p){
	vis[v] = 1;
	for(auto ve: g[v]) if(ve != p){
		if(!st.count({v, ve}) and !st.count({ve, v}))
			g2[v].emplace_back(ve), g3[ve].emplace_back(v), st.insert({v, ve});

		if(!vis[ve]) dfs(ve, v);
	}
}

vector<int> order;

void dfs2(int v){
	vis[v] = 1;
	for(auto ve: g2[v]) if(!vis[ve]) dfs2(ve);

	order.emplace_back(v);
}

void dfs3(int v){
	vis[v] = 1;
	for(auto ve: g3[v]) if(!vis[ve]) dfs3(ve);
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }

	memset(vis, 0, sizeof vis);
	dfs(0, -1);

	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; i++) if(!vis[i]) dfs2(i);
	reverse(order.begin(), order.end());

	memset(vis, 0, sizeof vis); int k = 1;
	for(auto o: order) if(!vis[o]) dfs3(o), k++;

	if(k > 2) cout << 0 << endl;
	else{
		for(int i = 0; i < n; i++) for(auto ve: g2[i]) cout << i+1 << ' ' << ve+1 << endl;
	}
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


