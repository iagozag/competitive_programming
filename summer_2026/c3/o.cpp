
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAXN = 1e5+10, MAXQ = 3e5+10, LINF = 0x3f3f3f3f3f3f3f3fll;

template<typename T> struct rmq {
	vector<T> v;
	int n; static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) { return v[x] < v[y] ? x : y; }
	int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
	rmq() {}
	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
			at = (at<<1)&((1<<b)-1);
			while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
		}
		for (int i = 0; i < n/b; i++) t[i] = b*i+b-1-msb(mask[b*i+b-1]);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
	T query(int l, int r) {
		if (r-l+1 <= b) return small(r, r-l+1);
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return ans;
	}
};

namespace lca {
	vector<int> g[MAXN];
	int v[2*MAXN], pos[MAXN], dep[2*MAXN];
	int t;
	rmq<int> RMQ;

	void dfs(int i, int d = 0, int p = -1) {
		v[t] = i, pos[i] = t, dep[t++] = d;
		for (int j : g[i]) if (j != p) {
			dfs(j, d+1, i);
			v[t] = i, dep[t++] = d;
		}
	}
	void build(int n, int root = 0) {
		t = 0;
		dfs(root);
		RMQ = rmq<int>(vector<int>(dep, dep+2*n-1));
	}
	int lca(int a, int b) {
		a = pos[a], b = pos[b];
		return v[RMQ.query(min(a, b), max(a, b))];
	}
	int dist(int a, int b) {
		return dep[pos[a]] + dep[pos[b]] - 2*dep[pos[lca(a, b)]];
	}
}

struct dsu {
	vector<int> id, sz;
	stack<stack<pair<int&, int>>> st;

	dsu(int n) : id(n), sz(n, 1) {
		iota(id.begin(), id.end(), 0), st.emplace();
	}

	void save(int &x) { st.top().emplace(x, x); }

	void checkpoint() { st.emplace(); }

	void rollback() {
		while(st.top().size()) {
			auto [end, val] = st.top().top(); st.top().pop();
			end = val;
		}
		st.pop();
	}

	int find(int a) { return a == id[a] ? a : find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		save(sz[a]), save(id[b]);
		sz[a] += sz[b], id[b] = a;
	}
};

int n, q;
vector<vector<pair<int, int>>> seg(4*MAXQ);
dsu d(MAXN);
vector<pair<int, int>> need(MAXQ, {-1, -1});

void add(pair<int, int>& edge, int a, int b, int p = 1, int l = 0, int r = q-1){
	if(a > r or b < l) return;
	if(a <= l and b >= r){ seg[p].emplace_back(edge); return; }

	int m = l+(r-l)/2;
	add(edge, a, b, p*2, l, m), add(edge, a, b, p*2+1, m+1, r);
}

void build(vector<pair<int, int>>& edges, vector<vector<pair<int, int>>>& v){
	for(int i = 0; i < n-1; i++)
		for(auto [a, b]: v[i]) add(edges[i], a, b);
}

void query(int p = 1, int l = 0, int r = q-1){
	d.checkpoint();
	for(auto [u, v]: seg[p]) d.unite(u, v);

	if(l == r){
 		if(need[l].first != -1){
			auto [u, v] = need[l];
			cout << (d.find(u) == d.find(v) ? lca::dist(u, v) : -1) << endl;
		}
	} else{
		int m = l+(r-l)/2;
		query(p*2, l, m);
		query(p*2+1, m+1, r);
	}

	d.rollback();
}

void solve(){
	cin >> n;
	vector<pair<int, int>> edges(n-1);
	for(int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b; --a, --b; edges[i] = {a, b};
		lca::g[a].emplace_back(b), lca::g[b].emplace_back(a);
	}

	lca::build(n);

	cin >> q;
	vector<vector<pair<int, int>>> interval(n-1);
	for(int i = 0; i < n-1; i++) interval[i].emplace_back(0, q-1);

	vector<tuple<int, int, int>> qu;
	for(int i = 0; i < q; i++){
		int op, a, b; cin >> op >> a; --a;

		if(op == 1) interval[a].emplace_back(i, q-1);
		else if(op == 2) interval[a].back().second = i;
		else{
			cin >> b, --b;
			need[i] = {a, b};
		}
	}

	build(edges, interval);
	query();
}

int32_t main(){
	int ttt = 1; // cin >> ttt;
	while(ttt--) solve();

	exit(0);
}
