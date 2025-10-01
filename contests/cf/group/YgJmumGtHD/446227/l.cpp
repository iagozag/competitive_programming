#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if(lazy[p] == -1) return;

		seg[p] = lazy[p]*(r-l+1);

		if (l != r) lazy[2*p] = lazy[2*p+1] = lazy[p];
		lazy[p] = -1;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int pai[MAX];
	int h[MAX], v[MAX], t;
	int d[MAX], p2[MAX], pp[MAX];

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = 0; sz[k] = 1;
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
	void update_path(int a, int b, int x) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b], pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	ll query_subtree(int a) {
		return seg::query(pos[a], pos[a]+sz[a]-1);
	}
	void update_subtree(int a, int x) {
		seg::update(pos[a], pos[a]+sz[a]-1, x);
	}

	//LCA
	void set_root(int i) { p2[i] = pp[i] = i, d[i] = 0; }

	void add_leaf(int i, int u) {
		p2[i] = u, d[i] = d[u]+1;
		pp[i] = 2*d[pp[u]] == d[pp[pp[u]]]+d[u] ? pp[pp[u]] : u;
	}

	int kth(int i, int k) {
		int dd = max(0, d[i]-k);
		while (d[i] > dd) i = d[pp[i]] >= dd ? pp[i] : p2[i];
		return i;
	}

	int lca(int a, int b) {
		if (d[a] < d[b]) swap(a, b);
		while (d[a] > d[b]) a = d[pp[a]] >= d[b] ? pp[a] : p2[a];
		while (a != b) {
			if (pp[a] != pp[b]) a = pp[a], b = pp[b];
			else a = p2[a], b = p2[b];
		}
		return a;
	}

	int dist(int a, int b) { return d[a]+d[b]-2*d[lca(a,b)]; }

	void build_lca(int i, int pai2=-1) {
		if (pai2 == -1) set_root(i);
		for (int j : g[i]) if (j != pai2) {
			add_leaf(j, i);
			build_lca(j, i);
		}
	}
}

void solve(){
	int N; cin >> N;
	for(int i = 0; i < N-1; i++){ int a, b; cin >> a >> b; --a, --b; hld::g[a].emplace_back(b), hld::g[b].emplace_back(a); }

	hld::build_lca(0);
	hld::build();

	int Q; cin >> Q;
	for(int i = 0; i < Q; i++){
		int op, v; cin >> op >> v; --v;

		if(op == 1 and !seg::query(hld::pos[v], hld::pos[v])){
			hld::update_subtree(v, 1);

			int l = 0, r = hld::dist(0, v), ans = v;
			while(l <= r){
				int m = (l+r)/2;
				int k = hld::kth(v, m);
				if(hld::query_subtree(k) == hld::sz[k]-m) ans = k, l = m+1;
				else r = m-1;
			}

			hld::update_subtree(ans, 1);
		}
		if(op == 2) hld::update_subtree(v, 0), hld::update_path(0, v, 0);
		if(op == 3) cout << hld::query_subtree(v) << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

