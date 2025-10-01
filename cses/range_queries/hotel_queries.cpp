#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;


namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
	// primeira posicao >= val em [a, b] (ou -1 se nao tem)
	int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (b < l or r < a or seg[p] < val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_left(a, b, val, 2*p, l, m);
		if (x != -1) return x;
		return get_left(a, b, val, 2*p+1, m+1, r);
	}
};

void solve(){
	int n, m; cin >> n >> m;
	int h[MAX]; for(int i = 0; i < n; i++) cin >> h[i];

	seg::build(n, h);

	for(int i = 0; i < m; i++){
		int r; cin >> r;
		int idx = seg::get_left(0, n-1, r);
		cout << idx+1 << ' ';
		if(idx != -1) seg::update(idx, idx, -r);
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
