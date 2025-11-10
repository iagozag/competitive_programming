#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

struct dsu_save {
    int v, rnkv, u, rnku;

    dsu_save() {}

    dsu_save(int _v, int _rnkv, int _u, int _rnku)
        : v(_v), rnkv(_rnkv), u(_u), rnku(_rnku) {}
};

struct dsu_with_rollbacks {
    vector<int> p, rnk;
    int comps;
    stack<dsu_save> op;

    dsu_with_rollbacks() {}

    dsu_with_rollbacks(int n) {
        p.resize(n);
        rnk.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            rnk[i] = 0;
        }
        comps = n;
    }

    int find_set(int v) {
        return (v == p[v]) ? v : find_set(p[v]);
    }

    bool unite(int v, int u) {
        v = find_set(v);
        u = find_set(u);
        if (v == u)
            return false;
        comps--;
        if (rnk[v] > rnk[u])
            swap(v, u);
        op.push(dsu_save(v, rnk[v], u, rnk[u]));
        p[v] = u;
        if (rnk[u] == rnk[v])
            rnk[u]++;
        return true;
    }

    void rollback() {
        if (op.empty())
            return;
        dsu_save x = op.top();
        op.pop();
        comps++;
        p[x.v] = x.v;
        rnk[x.v] = x.rnkv;
        p[x.u] = x.u;
        rnk[x.u] = x.rnku;
    }
};

vector<int> ans(MAX);
dsu_with_rollbacks g;

namespace seg {
	vector<tuple<int, int, int>> seg[4*MAX];
	int n;

	void build(int _n){
		n = _n;
	}

	void dfs(int p=1, int l=0, int r=n-1) {
		for(auto& [a, b, op]: seg[p]) op = g.unite(a, b);

		if(l == r){
			ans[l] = g.comps;
		} else{
			int m = (l+r)/2;
			dfs(2*p, l, m);
			dfs(2*p+1, m+1, r);
		}

		for(auto& [a, b, op]: seg[p]) if(op) g.rollback();
	}
	void update(int a, int b, int u, int v, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) {
			seg[p].emplace_back(u, v, 0);
			return;
		}
		if (b < l or r < a) return;
		int m = (l+r)/2;
		update(a, b, u, v, 2*p, l, m);
		update(a, b, u, v, 2*p+1, m+1, r);
	}
};

void solve(){
	int n, m, q; cin >> n >> m >> q;

	map<pair<int, int>, vector<pair<int, int>>> mp;
	for(int i = 0; i < m; i++){ 
		int a, b; cin >> a >> b; --a, --b; if(a > b) swap(a, b);
		mp[{a, b}].emplace_back(0, q);
	}

	for(int i = 1; i <= q; i++){
		int op, a, b; cin >> op >> a >> b; --a, --b; if(a > b) swap(a, b);
		if(op == 1) mp[{a, b}].emplace_back(i, q);
		else{
			pair<int, int>& prev = mp[{a, b}].back();
			prev.second = i-1;
		}
	}

	seg::build(q+1);
	for(auto [a, b]: mp) for(auto t: b) 
		seg::update(t.first, t.second, a.first, a.second);

	g = dsu_with_rollbacks(n);
	seg::dfs();
	
	for(int i = 0; i <= q; i++) cout << ans[i] << ' ';
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
