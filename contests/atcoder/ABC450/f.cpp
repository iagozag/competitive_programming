#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 998244353;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 1;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] *= lazy[p], seg[p] %= MOD;
		if (l != r) lazy[2*p] *= lazy[p], lazy[2*p] %= MOD, lazy[2*p+1] *= lazy[p], lazy[2*p+1] %= MOD;
		lazy[p] = 1;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return (query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r))%MOD;
	}
	ll updatemul(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = (lazy[p]*2)%MOD;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = (updatemul(a, b, 2*p, l, m) +
			updatemul(a, b, 2*p+1, m+1, r))%MOD;
	}
	ll updateidx(int idx, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (idx < l or r < idx) return seg[p];
		if (l == r) {
			seg[p] = x%MOD, lazy[p] = 1;
			return seg[p];
		}
		int m = (l+r)/2;
		return seg[p] = (updateidx(idx, x, 2*p, l, m) +
			updateidx(idx, x, 2*p+1, m+1, r))%MOD;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	int v[n]; memset(v, 0, sizeof v); v[0] = 1;
	seg::build(n, v);

	vector<pair<int, int>> edges(m);
	for(auto& [a, b]: edges) cin >> a >> b, --a, --b;
	sort(edges.begin(), edges.end());

	for(int i = 0; i < m; i++){
		auto [a, b] = edges[i];
		seg::updateidx(b, seg::query(a, b)+seg::query(b, b));
		seg::updatemul(b+1, n-1);
	}

	cout << seg::query(n-1, n-1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
