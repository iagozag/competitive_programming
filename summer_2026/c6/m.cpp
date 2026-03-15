#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 4e6, N = 1e6, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

// 1 = set 1
// 2 = set 0
// 3 = invert

namespace seg {
	int seg[MAX], lazy[MAX], R[MAX], L[MAX], ptr;
	int get_l(int i){
		if (L[i] == 0) L[i] = ptr++;
		return L[i];
	}
	int get_r(int i){
		if (R[i] == 0) R[i] = ptr++;
		return R[i];
	}

	void build() { ptr = 2; }

	void apply_lazy(int c, int op){
		if(op <= 2) lazy[c] = op;
		else{
			if(lazy[c] == 1) lazy[c] = 2;
			else if(lazy[c] == 2) lazy[c] = 1;
			else if(lazy[c] == 3) lazy[c] = 0;
			else lazy[c] = 3;
		}
	}

	void prop(int p, int l, int r) {
		if (!lazy[p]) return;

		if(lazy[p] == 1) seg[p] = r-l+1;
		else if(lazy[p] == 2) seg[p] = 0;
		else seg[p] = r-l+1-seg[p];

		if (l != r){
			apply_lazy(get_l(p), lazy[p]);
			apply_lazy(get_r(p), lazy[p]);
		}
		lazy[p] = 0;
	}

	int update(int a, int b, int op, int p=1, int l=0, int r=N-1) {
		prop(p, l, r);
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			lazy[p] = op;
			prop(p, l, r);
			return seg[p];
		}
		int m = (l+r)/2;
		return seg[p] = update(a, b, op, get_l(p), l, m)+update(a, b, op, get_r(p), m+1, r);
	}

	int query(int a, int b, int p=1, int l=0, int r=N-1) {
		prop(p, l, r);
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];

		int m = (l+r)/2;
		return query(a, b, get_l(p), l, m)+query(a, b, get_r(p), m+1, r);
	}

	int mex(int p=1, int l=0, int r=N-1) {
		prop(p, l, r);
		if(seg[p] == r-l+1) return -1;
		if (r == l) return l;

		int m = (l+r)/2;
		int x = mex(get_l(p), l, m);
		if(x != -1) return x;
		return mex(get_r(p), m+1, r);
	}
};

void solve(){
	int n; cin >> n;
	set<int> st = {0};
	vector<tuple<int, int, int>> qu(n); for(auto& [a, b, c]: qu) cin >> a >> b >> c, st.insert(b), st.insert(c);

	vector<int> v(st.begin(), st.end());
	for(auto x: v){
		if(x) st.insert(x-1);
		st.insert(x+1);
	}

	int k = 0; map<int, int> mp, mp_r;
	for(auto x: st) {
		mp[x] = k, mp_r[k++] = x;
	}

	seg::build();
	seg::update(0, 0, 1);

	for(auto [op, l, r]: qu){
		l = mp[l], r = mp[r];
		seg::update(l, r, op);

		cout << mp_r[seg::mex()] << endl;
	}
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}
