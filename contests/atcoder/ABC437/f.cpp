#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
typedef tuple<int, int, int, int> tp;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

vector<tp> seg(4*MAX, {LINF, -LINF, LINF, -LINF});

tp combine(tp a, tp b){
	auto [a1, b1, c1, d1] = a;
	auto [a2, b2, c2, d2] = b;
	return {min(a1, a2), max(b1, b2), min(c1, c2), max(d1, d2)};
}

tp update(int x, int y, int idx, int p = 1, int l = 0, int r = MAX-1){
	if(idx < l or idx > r) return seg[p];
	if(l == r)
		return seg[p] = {x+y, x+y, x-y, x-y};

	int m = l+(r-l)/2;
	return seg[p] = combine(update(x, y, idx, p*2, l, m), update(x, y, idx, p*2+1, m+1, r));
}

tp query(int a, int b, int p = 1, int l = 0, int r = MAX-1){
	if(a > r or b < l) return {LINF, -LINF, LINF, -LINF};
	if(a <= l and r <= b) return seg[p];

	int m = l+(r-l)/2;
	return combine(query(a, b, p*2, l, m), query(a, b, p*2+1, m+1, r));
}

void solve(){
	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		update(x, y, i);
	}

	for(int i = 0; i < q; i++){
		int op; cin >> op;
		if(op == 1){
			int idx, x, y; cin >> idx >> x >> y; --idx;
			update(x, y, idx);
		} else{
			int L, R, x, y; cin >> L >> R >> x >> y; --L, --R;
			auto [a, b, c, d] = query(L, R);

			int u = x+y, v = x-y;

			cout << max({abs(u-a), abs(u-b), abs(v-c), abs(v-d)}) << endl;
		}
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
