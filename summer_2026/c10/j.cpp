#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
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
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

void solve(){
	int n, m, L; cin >> n >> m >> L;
	vector<pair<int, int>> v(n); for(auto& [a, b]: v) cin >> a >> b;

	int k = 0;
	vector<pair<int, int>> f(m); for(auto& [x, idx]: f) cin >> x, idx = k++;
	sort(f.begin(), f.end());

	int arr[m]; memset(arr, 0, sizeof arr);
	seg::build(m, arr);

	for(auto [a, b]: v){
		int can = L-b;
		int ub = upper_bound(f.begin(), f.end(), make_pair(a+can, LINF))-f.begin();
		int lb = lower_bound(f.begin(), f.end(), make_pair(a-can, -1))-f.begin();
		if(ub-1 >= lb) seg::update(lb, ub-1, 1);
	}

	vector<int> ans(m);
	for(int i = 0; i < m; i++) ans[f[i].second] = seg::query(i, i);

	for(auto x: ans) cout << x << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


