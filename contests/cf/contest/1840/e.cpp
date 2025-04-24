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
	ll seg[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int x, int p=1, int l=0, int r=n-1) {
		if (a < l or r < a) return seg[p];
		if (l == r) {
			return seg[p] = x;
		}
		int m = (l+r)/2;
		return seg[p] = update(a, x, 2*p, l, m) +
			update(a, x, 2*p+1, m+1, r);
	}
};

void solve(){
	string a, b; cin >> a >> b; int n = a.size();
	int t, q; cin >> t >> q;

	int v[n] = {0};
	seg::build(n, v);

	for(int i = 0; i < n; i++) seg::update(i, a[i]==b[i]);

	vector<int> blocked(q, -1);
	int qnt = n;
	for(int i = 0; i < q; i++){
		if(blocked[i] != -1){
			qnt++;
			seg::update(blocked[i], a[blocked[i]] == b[blocked[i]]);
		}

		int op; cin >> op;
		if(op == 1){
			int pos; cin >> pos; pos--;
			qnt--;
			seg::update(pos, 0);
			if(i+t < q) blocked[i+t] = pos;
		} else if(op == 2){
			int s1, p1, s2, p2; cin >> s1 >> p1 >> s2 >> p2; --p1, --p2;
			swap(s1 == 1 ? a[p1] : b[p1], s2 == 1 ? a[p2] : b[p2]);
			seg::update(p1, a[p1]==b[p1]);
			seg::update(p2, a[p2]==b[p2]);
		} else{
			cout << (seg::query(0, n-1) == qnt ? "yes" : "no") << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
