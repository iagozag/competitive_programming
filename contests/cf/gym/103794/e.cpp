#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5e5+10, MOD = 1e9+7;

int n;
vector<int> v;

typedef tuple<int, int, int, int, int> tp;

pair<int, int> max_frac(int a, int b, int c, int d){
	return (a*d > c*b ? make_pair(a, b) : make_pair(c, d));
}

tp combine(tp a, tp b){
	auto [ma1, mi1, md1, mdpn1, mdpd1] = a;
	auto [ma2, mi2, md2, mdpn2, mdpd2] = b;

	pair<int, int> best = max_frac(mdpn1, mdpd1, mdpn2, mdpd2);

	int num = ma1-mi2, den = ma1, g = gcd(num, den);

	num /= g, den /= g;

	best = max_frac(num, den, best.first, best.second);

	return {max(ma1, ma2),
			min(mi1, mi2),
			max({md1, md2, ma1-mi2}),
			best.first,
			best.second};
}

tp seg[4*MAX];

tp build(int p = 1, int l = 0, int r = n-1){
	if(l == r) return seg[p] = {v[l], v[l], 0, 0, 1};
	int m = l+(r-l)/2;
	return seg[p] = combine(build(p*2, l, m),  build(p*2+1, m+1, r));
}

tp query(int a, int b, int p = 1, int l = 0, int r = n-1){
	if(a <= l and r <= b) return seg[p];
	if(b < l or a > r) return {0, INF, 0, 0, 1};
	int m = l+(r-l)/2;
	return combine(query(a, b, p*2, l, m), query(a, b, p*2+1, m+1, r));
}

void solve(){
	cin >> n;
	v = vector<int>(n); for(auto& x: v) cin >> x;

	build();

	int Q; cin >> Q;
	for(int q = 0; q < Q; q++){
		int a, b; cin >> a >> b; --a, --b;
		auto [ma, mi, md, mdpn, mdpd] = query(a, b);
		cout << md << ' ' << mdpn << ' ' << mdpd << endl;
	}
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
