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
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = __gcd(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}

	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return __gcd(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int> v(n); for(auto& x: v) cin >> x;
	int diff[n]; diff[0] = 0;
	for(int i = 1; i < n; i++) diff[i] = abs(v[i]-v[i-1]);

	seg::build(n, diff);

	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;
		cout << seg::query(a+1, b) << " ";
	}
	cout << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
