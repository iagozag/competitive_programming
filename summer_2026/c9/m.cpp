#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
};

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	ll query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b], pos[a]);
		return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
}

vector<int> vis, par, cyc, comp;
vector<vector<int>> g;

void make_cyc(int v, int ve){
	if(cyc[v] != -1) return;
	while(v != ve) cyc[ve] = v, ve = par[ve];
	cyc[v] = v;
}

void dfs(int v, int p, int cp){
	vis[v] = 1, par[v] = p, comp[v] = cp;
	for(auto ve: g[v]) if(ve != p){
		if(vis[ve]) make_cyc(ve, v);
		else dfs(ve, v, cp);
	}
}

int pot[MAX];

void solve(){
	int n, m; cin >> n >> m;
	g = vector<vector<int>>(n);
	for(int i = 0; i < m; i++){ int a, b; cin >> a >> b; --a, --b; g[a].emplace_back(b), g[b].emplace_back(a); }
	
	vis = par = comp = vector<int>(n);
	cyc = vector<int>(n, -1);

	int k = 0;
	for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, i, k++);

	for(int i = 0; i < n; i++){
		if(i == cyc[i]) hld::peso[i] = 1;

		if(cyc[i] == -1){
			for(auto ve: g[i]){
				if(cyc[ve] == -1) hld::g[i].emplace_back(ve);
				else hld::g[i].emplace_back(cyc[ve]);
			}
		} else{
			for(auto ve: g[i]) if(cyc[ve] != cyc[i]){
				if(cyc[ve] == -1) hld::g[cyc[i]].emplace_back(ve);
				else hld::g[cyc[i]].emplace_back(cyc[ve]);
			}
		}
	}

	hld::build();

	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;
		if(comp[a] != comp[b]){ cout << 0 << endl; continue; }

		if(cyc[a] != -1) a = cyc[a];
		if(cyc[b] != -1) b = cyc[b];
		cout << pot[hld::query_path(a, b)] << endl;
	}

}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	pot[0] = 1;
	for(int i = 1; i < MAX; i++) pot[i] = pot[i-1]*2%MOD;

    while(ttt--) solve();

    exit(0);
}
