#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

struct tp{
	int ans, ma1, mn1, ma2, mn2;

	tp(int x, int a, int b, int c, int d): ans(x), ma1(a), mn1(b), ma2(c), mn2(d) {}
};

int N, Q;
vector<tp> seg;
vector<int> v;

tp combine(const tp& a, const tp& b){
	return {max({a.ans, b.ans, b.ma1-a.mn1, a.ma2-b.mn2}), 
			max(a.ma1, b.ma1), 
			min(a.mn1, b.mn1),
			max(a.ma2, b.ma2), 
			min(a.mn2, b.mn2)};
}

tp build(int l = 0, int r = N-1, int p = 1){
	if(l == r) return seg[p] = {0, v[l]-l, v[l]-l, v[l]+l, v[l]+l};
	int m = (l+r)>>1;
	return seg[p] = combine(build(l, m, p<<1), build(m+1, r, (p<<1)+1));
}

tp update(int i, int x, int l = 0, int r = N-1, int p = 1){
	if(i < l or i > r) return seg[p];
	if(l == r) return seg[p] = {0, x-i, x-i, x+i, x+i};
	int m = (l+r)>>1;
	return seg[p] = combine(update(i, x, l, m, p<<1), update(i, x, m+1, r, (p<<1)+1));
}

void solve(){
	cin >> N >> Q; seg = vector<tp>(N<<2, {0, -INF, INF, -INF, INF});
	v = vector<int>(N); for(auto& x: v) cin >> x;

	build();

	cout << seg[1].ans << endl;

	for(int i = 0; i < Q; i++){
		int idx, val; cin >> idx >> val; --idx;
		update(idx, val);
		cout << seg[1].ans << endl;
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
