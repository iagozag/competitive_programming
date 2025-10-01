#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1.2e5+10, MOD = 1e9+7;

int n, q;
int a[MAX];
vector<int> g[MAX];
map<int, int> mp, mp_r;

// LCA com RMQ
//
// Assume que um vertice eh ancestral dele mesmo, ou seja,
// se a eh ancestral de b, lca(a, b) = a
// dist(a, b) retorna a distancia entre a e b
//
// Complexidades:
// build - O(n)
// lca - O(1)
// dist - O(1)

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
	int v[2*MAX], pos[MAX], dep[2*MAX];
	int t;
	rmq<int> RMQ;

	void dfs(int i, int d = 0, int p = -1) {
		v[t] = i, pos[i] = t, dep[t++] = d;
		for (int j : g[i]) if (j != p) {
			dfs(j, d+1, i);
			v[t] = i, dep[t++] = d;
		}
	}
	void build(int n, int root) {
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

struct Node{
	Node *l, *r;
	int sum = 0;
	Node(int _sum): sum(_sum) {}
	Node(Node* _l, Node* _r) {
		l = _l, r = _r;

		if(l) sum += l->sum;
		if(r) sum += r->sum;
	}
	Node(Node* cp): l(cp->l), r(cp->r), sum(cp->sum) {}
};

Node* roots[MAX];

Node* build(int l = 0, int r = MAX-1){
	if(l == r) return new Node((int)0);

	int m = l+(r-l)/2;
	return new Node(build(l, m), build(m+1, r));
}

Node* update(Node* p, int pos, int l = 0, int r = MAX-1){
	if(l == r) return new Node(p->sum+1);

	int m = l+(r-l)/2;
	if(pos <= m) return new Node(update(p->l, pos, l, m), p->r);
	return new Node(p->l, update(p->r, pos, m+1, r));
}

int find_kth(Node* vl, Node* vr, Node* vm, Node* vmp, int l, int r, int k){
	if(l == r) return l;

	int sl = vl->l->sum, sr = vr->l->sum, sm = vm->l->sum, smp = vmp->l->sum, tot = sr+sl-sm-smp;
	int m = l+(r-l)/2;

	if(k <= tot) return find_kth(vl->l, vr->l, vm->l, vmp->l, l, m, k);
	return find_kth(vl->r, vr->r, vm->r, vmp->r, m+1, r, k-tot);
}

int cnt = 1;
int version[MAX], par[MAX];

void dfs(int v, int p){
	par[v] = p;

	version[v] = cnt;
	roots[cnt] = new Node(roots[version[p]]);
	roots[cnt] = update(roots[cnt], a[v]);
	cnt++;

	for(auto ve: g[v]) if(ve != p) dfs(ve, v);
}

int find_kth(int u, int v, int k){
	int c = lca::lca(u, v);
	
	return find_kth(roots[version[u]], roots[version[v]], roots[version[c]], roots[version[par[c]]], 0, MAX-1, k);
}

void solve(){
	cin >> n >> q;
	set<int> st;
	for(int i = 1; i <= n; i++) cin >> a[i], st.insert(a[i]);
	for(int i = 0; i < n-1; i++){ int u, v; cin >> u >> v; g[u].emplace_back(v), g[v].emplace_back(u); }

	roots[0] = build();

	lca::build(n, 1);
	
	int idx = 0;
	for(auto x: st) mp[x] = idx, mp_r[idx++] = x;
	for(int i = 1; i <= n; i++) a[i] = mp[a[i]];

	dfs(1, 0);

	for(int i = 0; i < q; i++){
		int u, v, k; cin >> u >> v >> k;
		cout << mp_r[find_kth(u, v, k)] << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
