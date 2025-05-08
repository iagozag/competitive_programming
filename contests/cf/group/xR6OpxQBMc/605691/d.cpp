#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int d[MAX], p[MAX], pp[MAX];

void set_root(int i) { p[i] = pp[i] = i, d[i] = 0; }

void add_leaf(int i, int u) {
	p[i] = u, d[i] = d[u]+1;
	pp[i] = 2*d[pp[u]] == d[pp[pp[u]]]+d[u] ? pp[pp[u]] : u;
}

int kth(int i, int k) {
	int dd = max(0LL, d[i]-k);
	while (d[i] > dd) i = d[pp[i]] >= dd ? pp[i] : p[i];
	return i;
}

int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	while (d[a] > d[b]) a = d[pp[a]] >= d[b] ? pp[a] : p[a];
	while (a != b) {
		if (pp[a] != pp[b]) a = pp[a], b = pp[b];
		else a = p[a], b = p[b];
	}
	return a;
}

int dist(int a, int b) { return d[a]+d[b]-2*d[lca(a,b)]; }

vector<int> g[MAX];

void build(int i, int pai=-1) {
	if (pai == -1) set_root(i);
	for (int j : g[i]) if (j != pai) {
		add_leaf(j, i);
		build(j, i);
	}
}

vector<int> dp(MAX);

int dfs(int v, int par){
	dp[v] = 1;
	for(auto ve: g[v]) if(ve != par) dp[v] += dfs(ve, v);
	return dp[v];
}

void solve(){
	int n, q; cin >> n >> q;
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b;
		g[a].emplace_back(b), g[b].emplace_back(a);
	}

	dfs(0, -1);

	build(0);

	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;

		if(d[a] < d[b]) swap(a, b);

		int di = dist(a, b);

		if(di&1){ cout << 0 << endl; continue; }

		di >>= 1;

		int mid = (d[a] == d[b] ? lca(a, b) : kth(a, di));
		int anca = kth(a, di-1);
		if(d[a] == d[b]) cout << n-dp[anca]-dp[kth(b, di-1)] << endl;
		else cout << dp[mid]-dp[anca] << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
