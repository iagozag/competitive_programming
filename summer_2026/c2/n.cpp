#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10, MOD = 1e9+7;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX], ld[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = ld[p] = -1;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if(lazy[p] == -1) return;

		int m = (l+r)/2, sz = r-l+1, szl = m-l+1, rest = ld[p]-sz;
		seg[p] = lazy[p]*(ld[p]*(ld[p]+1)/2 - rest*(rest+1)/2);

		if (l != r){
			lazy[2*p] = lazy[2*p+1] = lazy[p];
			ld[2*p] = ld[p], ld[2*p+1] = ld[p]-szl;
		}
		lazy[p] = ld[p] = -1;
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
			int d = b-a+1;
			lazy[p] = x, ld[p] = d-(l-a);
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

set<pair<int, int>> st;

void update(int a, int b){
	auto it = st.upper_bound(make_pair(a, 0));
	it--;

	int l = it->first;
	if(l+1 < a) seg::update(l+1, a-1, it->second);

	it++;
	int r = it->first;
	if(a+1 < r) seg::update(a+1, r-1, b);

	st.insert(make_pair(a, b));
	seg::update(a, a, 0);
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int>> v(m);
	for(int i = 0; i < m; i++) cin >> v[i].first, v[i].first--;
	for(int i = 0; i < m; i++) cin >> v[i].second;
	sort(v.begin(), v.end());

	int arr[n] = {0};
	seg::build(n, arr);

	seg::update(1, n-2, v[0].second);
	st.insert({v[0].first, v[0].second}), st.insert({v[m-1].first, v[m-1].second});

	for(int i = 1; i < m-1; i++) update(v[i].first, v[i].second);
	
	for(int qq = 0; qq < q; qq++){
		int op, a, b; cin >> op >> a >> b; --a;
		if(op == 1){
			update(a, b);
		} else{
			--b;
			cout << seg::query(a, b) << endl;
		}
	}

}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
