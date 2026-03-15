#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10, MOD = 1e9+7;

pair<int, int> comb(pair<int, int> a, pair<int, int> b){
	return {a.first^b.first, a.second+b.second};
}

namespace seg {
	pair<int, int> seg[4*MAX]; int lazy[4*MAX];
	int n, *v;

	pair<int, int> build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = {v[l], 0};
		int m = (l+r)/2;
		return seg[p] = comb(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if(!lazy[p]) return;
		seg[p].second = (r-l+1);
		if (l != r) lazy[2*p] = lazy[2*p+1] = lazy[p];
		lazy[p] = 0;
	}
	pair<int, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {0, 0};
		int m = (l+r)/2;
		return comb(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	pair<int, int> update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = comb(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

namespace hld {
	vector<pair<int, int>> g[MAX];
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.first != p) {
			auto [u, w] = i;
			sobe[u] = w; pai[u] = k;
			h[u] = (i == g[k][0] ? h[k] : u);
			build_hld(u, k, f); sz[k] += sz[u];

			if (sz[u] > sz[g[k][0].first] or g[k][0].first == p)
				swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	pair<int, int> query_path(int a, int b) {
		if (a == b) return {0, 0};
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
		return comb(seg::query(pos[h[a]], pos[a]), query_path(pai[h[a]], b));
	}
	void update_path(int a, int b, int x) {
		if (a == b) return;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b]+1, pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	pair<int, int> query_subtree(int a) {
		if (sz[a] == 1) return {0, 0};
		return seg::query(pos[a]+1, pos[a]+sz[a]-1);
	}
	void update_subtree(int a, int x) {
		if (sz[a] == 1) return;
		seg::update(pos[a]+1, pos[a]+sz[a]-1, x);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
}

vector<int> id, sz;

int find(int x){ return id[x] = id[x] == x ? x : find(id[x]); }

void unio(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b], id[b] = a;
}

void solve(){
	int n, q; cin >> n >> q;
	sz = id = vector<int>(n, 1); iota(id.begin(), id.end(), 0);

	vector<bool> ans(q); vector<tuple<int, int, int, int>> edges;
	for(int i = 0; i < q; i++){
		int a, b, w; cin >> a >> b >> w; --a, --b;
		if(find(a) != find(b)) ans[i] = 1, unio(a, b), hld::g[a].emplace_back(b, w), hld::g[b].emplace_back(a, w);
		else edges.emplace_back(a, b, w, i);
	}

	for(int i = 0; i < n; i++) if(find(i) == i) hld::g[i].emplace_back(n, 0), hld::g[n].emplace_back(i, 0);

	hld::build(n);

	for(auto [a, b, w, idx]: edges){
		auto [x, s] = hld::query_path(a, b);
		if(s > 0 or (x^w) == 0) continue;
		ans[idx] = 1;
		hld::update_path(a, b, 1);
	}

	for(auto x: ans) cout << (x ? "YES" : "NO") << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
