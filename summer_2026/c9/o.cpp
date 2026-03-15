#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int n;
vector<int> g[MAX], g2[MAX], comp[MAX];
int c[MAX], vis[MAX], viss[MAX];
vector<int> order;

void dfs(int v, int k = 1, bool g1 = 1){
	vis[v] = k;
	for(auto ve: (g1 ? g[v] : g2[v])) if(!vis[ve]) dfs(ve, k, g1);

	if(g1) order.emplace_back(v);
}

vector<int> color, best;
int dfs2(int v){
	viss[v] = 1; int ma = 0;
	for(auto ve: comp[v]){
		if(!viss[ve]) ma = max(ma, dfs2(ve));
		else ma = max(ma, best[ve]);
	}
	return best[v] = ma+color[v];
}

void solve(){
	int m; cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> c[i];

	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g2[b].emplace_back(a); }

	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, 1, 1);
	reverse(order.begin(), order.end());

	memset(vis, 0, sizeof vis); int k = 1;
	for(auto o: order) if(!vis[o]) dfs(o, k, 0), k++;

	for(int i = 0; i < n; i++) for(auto ve: g[i]) if(vis[i] != vis[ve]) comp[vis[i]].emplace_back(vis[ve]);

	color = best = vector<int>(k+1);
	for(int i = 0; i < n; i++)
		color[vis[i]] += c[i];

	memset(viss, 0, sizeof viss);
	int ans = 0;
	for(int	i = 0; i < k; i++) if(!viss[vis[i]]) ans = max(ans, dfs2(vis[i]));

	cout << ans << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


