#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10, MOD = 1e9+7;

namespace seg {
	pair<int, int> seg[4*MAX];
	int n, *v;

	pair<int, int> combine(pair<int, int> a, pair<int, int> b){
		return {min(a.first, b.first), max(a.second, b.second)};
	}

	pair<int, int> build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {INF, 0};
		int m = (l+r)/2;
		return seg[p] = combine(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void buildd(int n2) {
		n = n2;
		build();
	}
	pair<int, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {INF, 0};
		int m = (l+r)/2;
		return combine(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	pair<int, int> update(int a, int b, int x, int op, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) {
			if(op == 0) seg[p].first = x;
			else seg[p].second = x;
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = combine(update(a, b, x, op, 2*p, l, m),
			update(a, b, x, op, 2*p+1, m+1, r));
	}
};

void solve(){
	int n, q; cin >> n >> q;

	seg::buildd(n+1);

	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b;
		pair<int, int> x = seg::query(a, b);
		if(x.first < a or x.second > b){ cout << "No" << endl; continue; }

		seg::update(b, b, a, 0);
		seg::update(a, a, b, 1);
		cout << "Yes" << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
