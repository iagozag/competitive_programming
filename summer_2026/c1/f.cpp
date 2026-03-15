#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 40010, LINF = 0x3f3f3f3f3f3f3f3fll;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n;
	vector<int> v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, vector<int>& v2) {
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
		if (b < l or r < a) return LINF;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
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
		return seg[p] = min(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

void solve(){
	int n; cin >> n;
	set<int> st;
	vector<pair<int, int>> v(n); 
	for(auto& x: v){
		cin >> x.first >> x.second, --x.first, --x.second;
		st.insert(x.first);
		st.insert(x.second);
	}

	int k = 0; map<int, int> mp;
	for(auto x: st) mp[x] = k++;

	for(auto& [a, b]: v) a = mp[a], b = mp[b];

	vector<int> tmp(k+10);
	seg::build(k+10, tmp);

	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		auto [a, b] = v[i];
		if(seg::query(a, b) == 0) ans++;
		seg::update(a, b, 1);
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
