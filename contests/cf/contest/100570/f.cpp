#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

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
    vector<pair<int, int>> g[MAX]; 
    int v[2*MAX], pos[MAX], dep[2*MAX];
    
    long long dist_path[MAX]; 
    
    int t;
    rmq<int> RMQ;

    void dfs(int i, int d = 0, int p = -1, long long current_dist = 0) {
        v[t] = i, pos[i] = t, dep[t++] = d;
        dist_path[i] = current_dist;
        
        for (auto [j, w] : g[i]) if (j != p) {
            dfs(j, d+1, i, current_dist + w);
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

    long long dist(int a, int b) {
        return dist_path[a] + dist_path[b] - 2 * dist_path[lca(a, b)];
    }
}

vector<pair<int, int>> g[MAX];
vector<int> d[MAX], dp[MAX];
int sz[MAX], rem[MAX], par[MAX];

int dfs_sz(int i, int l=-1) {
	sz[i] = 1;
	for (auto [j, w] : g[i]) if (j != l and !rem[j]) sz[i] += dfs_sz(j, i);
	return sz[i];
}

int centroid(int i, int l, int size) {
	for (auto [j, w] : g[i]) if (j != l and !rem[j] and sz[j] > size / 2)
		return centroid(j, i, size);
	return i;
}

void dfs(vector<int>& nodes, int i, int l=-1) {
    nodes.push_back(i);
    for (auto [j, w] : g[i]) if (j != l and !rem[j]) dfs(nodes, j, i);
}

void decomp(int i, int pp = -1) {
    int c = centroid(i, i, dfs_sz(i));
    rem[c] = 1, par[c] = pp;

    vector<int> nodes;
    dfs(nodes, c);

    for(auto u : nodes) d[c].push_back(lca::dist(c, u));
    sort(d[c].begin(), d[c].end());

    if (pp != -1) {
        for(auto u : nodes) dp[c].push_back(lca::dist(pp, u));
        sort(dp[c].begin(), dp[c].end());
    }

    for (auto [j, w] : g[c]) if (!rem[j]) decomp(j, c);
}

int query(int u, int l){
	int x = u, dd = l;
	int ans = upper_bound(d[x].begin(), d[x].end(), dd)-d[x].begin();
	while(1){
		if(par[x] == -1) break;

		int ddd = l-lca::dist(u,par[x]);
		int add = upper_bound(d[par[x]].begin(), d[par[x]].end(), ddd)-d[par[x]].begin();
		int sub = upper_bound(dp[x].begin(), dp[x].end(), ddd) - dp[x].begin();

		ans += add-sub;
		x = par[x];
	}
	return ans;
}

void solve(){
	int n, q; cin >> n >> q;

	for(int i = 0; i < n-1; i++){ 
		int a, b, w; cin >> a >> b >> w; --a, --b; 
		g[a].emplace_back(b, w), g[b].emplace_back(a, w); 
		lca::g[a].emplace_back(b, w), lca::g[b].emplace_back(a, w); 
	}

	lca::build(n, 0);

	decomp(0);

	for(int qq = 0; qq < q; qq++){
		int v, l; cin >> v >> l; --v;
		cout << query(v, l) << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

	memset(sz, 0, sizeof sz);
	memset(rem, 0, sizeof rem);
	memset(par, 0, sizeof par);

    while(ttt--) solve();

    exit(0);
}

