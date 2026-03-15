#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld EPS = 1e-6;

const int MAX = 1e5+20, MOD = 1e9+7;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void buildd(int n2) {
		n = n2;
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
		if (b < l or r < a) return -LINF;
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
};

int n, d;
vector<pair<int, ld>> v;

ld dist(int i, int j){
	return (v[i].second > v[j].second ? 360.0 : 0)+v[j].second-v[i].second;
}

void solve(){
	int D = 1e5+10;
	seg::buildd(D);

	ld a; cin >> n >> d >> a;
	v.resize(n);
	for(auto& x: v) cin >> x.first >> x.second;
	sort(v.begin(), v.end(), [&](pair<int, ld> f, pair<int, ld> s){
		if(abs(f.second-s.second) > EPS) return f.second < s.second;
		return f.first < s.first;
	});
	for(int i = 0; i < n; i++) v.push_back(v[i]);

	int l = 0, r = 0, ans = 0;
	while(l < n and r-l < n){
		while(r-l < n and a-dist(l, r) > -EPS){
			seg::update(max(0ll, v[r].first-d), v[r].first, 1);
			r++;
		}

		ans = max(ans, seg::query(0, D-1));

		seg::update(max(0ll, v[l].first-d), v[l].first, -1);
		l++;
		if(l > r){
			seg::update(max(0ll, v[r].first-d), v[r].first, 1);
			r++;
		}
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}


