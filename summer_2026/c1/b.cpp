#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;
const int MAX = 30001, LINF = 0x3f3f3f3f3f3f3f3fll;

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


int32_t main(){
	for(int t = 1; t <= 10; t++){
		cout << "Test " << t << ":" << endl;

		int n, sum = 0; cin >> n;
		vector<int> v(n), pref(n); 
		for(int i = 0; i < n; i++){ 
			char c; cin >> c; v[i] = (c == '(' ? 1 : -1); 
			sum += v[i], pref[i] = (i ? pref[i-1] : 0) + v[i];
		}

		seg::build(n, pref);
		
		int q; cin >> q;
		for(int i = 0; i < q; i++){
			int x; cin >> x; 
			if(x == 0){
				cout << (seg::query(0, n-1) >= 0 and sum == 0 ? "YES" : "NO") << endl;
			} else{
				x--;
				if(v[x] == 1) v[x] = -1, sum -= 2, seg::update(x, n-1, -2);
				else v[x] = 1, sum += 2, seg::update(x, n-1, 2);
			}
		}
	}
}
