#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

// Li-Chao Tree
//
// Adiciona retas (ax+b), e computa o minimo entre as retas
// em um dado 'x'
// Cuidado com overflow!
// Se tiver overflow, tenta comprimir o 'x' ou usar
// convex hull trick
//
// O(log(MA-MI)), O(n) de memoria

template<ll MI = ll(-1e9), ll MA = ll(1e9)> struct lichao {
	struct line {
		ll a, b;
		array<int, 2> ch;
		line(ll a_ = 0, ll b_ = LINF) :
			a(a_), b(b_), ch({-1, -1}) {}
		ll operator ()(ll x) { return a*x + b; }
	};
	vector<line> ln;

	int ch(int p, int d) {
		if (ln[p].ch[d] == -1) {
			ln[p].ch[d] = ln.size();
			ln.emplace_back();
		}
		return ln[p].ch[d];
	}
	lichao() { ln.emplace_back(); }

	void add(line s, ll l=MI, ll r=MA, int p=0) {
		ll m = (l+r)/2;
		bool L = s(l) < ln[p](l);
		bool M = s(m) < ln[p](m);
		bool R = s(r) < ln[p](r);
		if (M) swap(ln[p], s), swap(ln[p].ch, s.ch);
		if (s.b == LINF) return;
		if (L != M) add(s, l, m-1, ch(p, 0));
		else if (R != M) add(s, m+1, r, ch(p, 1));
	}
	ll query(int x, ll l=MI, ll r=MA, int p=0) {
		ll m = (l+r)/2, ret = ln[p](x);
		if (ret == LINF) return ret;
		if (x < m) return min(ret, query(x, l, m-1, ch(p, 0)));
		return min(ret, query(x, m+1, r, ch(p, 1)));
	}
};

int n;
int a[MAX], b[MAX], ans[MAX], sz[MAX];
vector<int> g[MAX];

void dfs_sz(int v, int p){
	sz[v] = 1;
	for(auto ve: g[v]) if(ve != p) dfs_sz(ve, v), sz[v] += sz[ve];
}

void dfs(int v, int p, lichao<>& l){
	int u = -1, ma = 0;
	for(auto ve: g[v]) if(ve != p and sz[ve] > ma) ma = sz[ve], u = ve;
	
	if(u != -1) dfs(u, v, l);

	for(auto ve: g[v]) if(ve != u and ve != p){
		lichao<> tmp;
		dfs(ve, v, tmp);
		for(auto lin: tmp.ln) l.add(lin);
	}

	if(u != -1) ans[v] = l.query(a[v]);

	l.add({b[v], ans[v]});
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	for(int i = 0; i < n-1; i++){ int u, v; cin >> u >> v; --u, --v; g[u].emplace_back(v), g[v].emplace_back(u); }

	memset(sz, 0, sizeof sz);
	dfs_sz(0, -1);

	memset(ans, 0, sizeof ans);

	lichao<> l;
	dfs(0, -1, l);

	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
