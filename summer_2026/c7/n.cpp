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

	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	bool unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
		return true;
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<dsu> g(11, dsu(n));

	int ans = 0;
	for(int i = 0; i < n-1; i++){
		int a, b, c; cin >> a >> b >> c; --a, --b;

		if(!g[c].unite(a, b)) continue;

		ans += c; bool ok = true;
		for(int j = c+1; j <= 10; j++){
			if(g[j].find(a) == g[j].find(b) and ok){ ans -= j; ok = false; }
			g[j].unite(a, b);
		}
	}

	for(int i = 0; i < q; i++){
		int a, b, c; cin >> a >> b >> c; --a, --b;

		if(!g[c].unite(a, b)){ cout << ans << endl; continue; }

		ans += c; bool ok = true;
		for(int j = c+1; j <= 10; j++){
			if(g[j].find(a) == g[j].find(b) and ok){ ans -= j; ok = false; }
			g[j].unite(a, b);
		}

		cout << ans << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
