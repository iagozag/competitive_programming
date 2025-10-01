#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7, LOG = ceil(log2(MAX));

typedef tuple<int, int, int, int> tp;
// max pref, max suf, sum, ans

namespace seg {
	tp seg[4*MAX];
	int n, *v;

	tp junta(tp a, tp b){
		tp c;
		auto& [a1, a2, a3, a4] = a;
		auto& [b1, b2, b3, b4] = b;
		auto& [c1, c2, c3, c4] = c;
		c1 = max(a1, a3+b1);
		c2 = max(b2, b3+a2);
		c3 = a3+b3;
		c4 = max({a4, b4, a2+b1});

		return c;
	}

	tp build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {v[l], v[l], v[l], v[l]};
		int m = (l+r)/2;
		return seg[p] = junta(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	tp query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {-LINF, -LINF, 0, -LINF};
		int m = (l+r)/2;
		return junta(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
};

void solve(){
	int n, q; cin >> n >> q;
	int v[MAX];
	for(int i = 0; i < n; i++) cin >> v[i];

	seg::build(n, v);

	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b; --a, --b;
		cout << max(0LL, get<3>(seg::query(a, b))) << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
