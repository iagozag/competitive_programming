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
		lazy[p] = LINF;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] = min(seg[p], lazy[p]);
		if (l != r) lazy[2*p] = min(lazy[2*p], lazy[p]), lazy[2*p+1] = min(lazy[2*p+1], lazy[p]);
		lazy[p] = LINF;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return LINF;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = min(lazy[p], x);
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = min(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

void solve(){
	int h, w, n; cin >> h >> w >> n;
	vector<vector<int>> v(n);
	for(int i = 0; i < n; i++){
		int a, b, c; cin >> a >> b >> c;
		v[i] = {a, b, c, i};
	}
	sort(v.begin(), v.end(), greater<vector<int>>());
	int arr[w+1]; for(int i = 0; i < w+1; i++) arr[i] = h+1;
	seg::build(w+1, arr);

	vector<int> ans(n);
	for(int i = 0; i < n; i++){
		int a = v[i][0], b = v[i][1], c = v[i][2], idx = v[i][3];
		ans[idx] = seg::query(b, b+c-1)-1;
		seg::update(b, b+c-1, ans[idx]);
	}
	for(auto x: ans) cout << x << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
