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
	tuple<int, int, int> seg[4*MAX];
	int lazy[4*MAX];
	int n;
	vector<int> v;

	tuple<int, int, int> combine(tuple<int, int, int> a, tuple<int, int, int> b){
		auto [a1, a2, a3] = a;
		auto [b1, b2, b3] = b;
		return {a1+b1, a2+b2, a3+b3};
	}

	tuple<int, int, int> build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1;
		if (l == r){
			if(v[l] == 0) return seg[p] = {1, 0, 0};
			else if(v[l] == 1) return seg[p] = {0, 1, 0};
			return seg[p] = {0, 0, 1};
		}
		int m = (l+r)/2;
		return seg[p] = combine(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, vector<int>& v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if(lazy[p] == 0) seg[p] = {r-l+1, 0, 0};
		if(lazy[p] == 1) seg[p] = {0, r-l+1, 0};
		if(lazy[p] == 2) seg[p] = {0, 0, r-l+1};

		if (l != r and lazy[p] != -1) lazy[2*p] = lazy[2*p+1] = lazy[p];
		lazy[p] = -1;
	}
	tuple<int, int, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {0, 0, 0};
		int m = (l+r)/2;
		return combine(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	tuple<int, int, int> update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = combine(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

void solve(){
	int n, q, x; cin >> n >> q >> x;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] < x) v[i] = 0;
		else if(v[i] == x) v[i] = 1;
		else v[i] = 2;
	}

	seg::build(n, v);

	for(int i = 0; i < q; i++){
		int op, a, b; cin >> op >> a >> b; --a, --b;

		auto [q0, q1, q2] = seg::query(a, b);

		if(op == 1){
			if(q0) seg::update(a, a+q0-1, 0);
			if(q1) seg::update(a+q0, a+q0+q1-1, 1);
			if(q2) seg::update(a+q0+q1, b, 2);
		} else{
			if(q2) seg::update(a, a+q2-1, 2);
			if(q1) seg::update(a+q2, a+q2+q1-1, 1);
			if(q0) seg::update(a+q2+q1, b, 0);
		}
	}

	for(int i = 0; i < n; i++){
		auto [q0, q1, q2] = seg::query(i, i);
		if(q1){ cout << i+1 << endl; return; }
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
