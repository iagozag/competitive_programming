#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int n;
vector<int> g[MAX], g2[MAX];
int c[MAX], vis[MAX];
vector<int> order;

void dfs(int v, int k = 1, bool g1 = 1){
	vis[v] = k;
	for(auto ve: (g1 ? g[v] : g2[v])) if(!vis[ve]) dfs(ve, k, g1);

	if(g1) order.emplace_back(v);
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> c[i];

	int m; cin >> m;
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g2[b].emplace_back(a); }

	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, 1, 1);
	reverse(order.begin(), order.end());

	memset(vis, 0, sizeof vis); int k = 1;
	for(auto o: order) if(!vis[o]) dfs(o, k, 0), k++;

	vector<pair<int, int>> color(k+1, {LINF, 1});
	for(int i = 0; i < n; i++){
		if(color[vis[i]].first == c[i]) color[vis[i]].second++;
		if(color[vis[i]].first > c[i]) color[vis[i]] = {c[i], 1};
	}

	int ans = 1, total = 0;
	for(int i = 1; i < k; i++) total += color[i].first, ans *= color[i].second, ans %= MOD;
	cout << total << ' ' << ans << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


