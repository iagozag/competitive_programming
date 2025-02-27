#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;

struct Seg {
	ll seg[4*MAX];
	int n;

	Seg(int _n): n(_n){}

	ll query(int a, int b, int p, int l, int r) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}

	ll update(int idx, int x, int p, int l, int r) {
		if (idx < l or r < idx) return seg[p];
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		return seg[p] = max(update(idx, x, 2*p, l, m),
			update(idx, x, 2*p+1, m+1, r));
	}
};

void solve(){
	int n; cin >> n;
	vector<pair<int, int>> v(n); vector<int> a(n);
	for(int i = 0; i < n; i++){ int x; cin >> x; v[x-1].first = i, a[i] = x-1; }
	for(int i = 0; i < n; i++){ int x; cin >> x; v[x-1].second = i; }

	Seg s1(n), s2(n);
	for(int i = 0; i < n; i++){
		int mi = min((v[a[i]].first ? s1.query(0, v[a[i]].first-1, 1, 0, n-1) : 0), 
					 (v[a[i]].second ? s2.query(0, v[a[i]].second-1, 1, 0, n-1) : 0))+1;

		s1.update(v[a[i]].first, mi, 1, 0, n-1), s2.update(v[a[i]].second, mi, 1, 0, n-1);
	}

	cout << s1.query(0, n-1, 1, 0, n-1) << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
