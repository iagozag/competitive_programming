#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

struct dsu {
	vector<int> id, sz;
	stack<stack<pair<int&, int>>> st;
	int bip;

	dsu() {}

	dsu(int n) : id(n), sz(n, 1), bip(1) {
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

	void _unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		save(sz[a]), save(id[b]);
		sz[a] += sz[b], id[b] = a;
	}

	void unite(int a, int b){
		_unite(a*2, b*2+1), _unite(a*2+1, b*2);
		if(find(a*2) == find(a*2+1)){
			save(bip);
			bip = 0;
		}
	}
};

vector<int> ans(MAX);
dsu g;

namespace seg {
	vector<pair<int, int>> seg[4*MAX];
	vector<int> ok(MAX, 1);
	int n;

	void build(int _n){
		n = _n;
	}

	void dfs(int p=1, int l=0, int r=n-1) {
		g.checkpoint();

		for(auto [a, b]: seg[p]) 
			g.unite(a, b);

		if(l == r){
			ans[l] = g.bip;
		} else{
			int m = (l+r)/2;
			dfs(2*p, l, m);
			dfs(2*p+1, m+1, r);
		}

		g.rollback();

	}
	void update(int a, int b, int u, int v, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) {
			seg[p].emplace_back(u, v);
			return;
		}
		if (b < l or r < a) return;
		int m = (l+r)/2;
		update(a, b, u, v, 2*p, l, m);
		update(a, b, u, v, 2*p+1, m+1, r);
	}
};

void solve(){
	int n, q; cin >> n >> q;

	map<pair<int, int>, vector<pair<int, int>>> mp;
	set<pair<int, int>> st;
	for(int i = 1; i <= q; i++){
		int a, b; cin >> a >> b; --a, --b; if(a > b) swap(a, b);
		if(!st.count({a, b})) mp[{a, b}].emplace_back(i, q), st.insert({a, b});
		else{
			pair<int, int>& prev = mp[{a, b}].back();
			prev.second = i-1;
			st.erase({a, b});
		}
	}

	seg::build(q+1);
	for(auto [a, b]: mp) for(auto t: b) 
		seg::update(t.first, t.second, a.first, a.second);

	g = dsu(2*n);
	seg::dfs();
	
	for(int i = 1; i <= q; i++) cout << (ans[i] ? "YES" : "NO") << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

