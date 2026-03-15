#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

#define sq(x) ((x)*(ll)(x))

struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

int n;
vector<pt> v;

int seg[4*MAX];

int build(int p = 1, int l = 0, int r = n-1){
	if(l == r) return seg[p] = 0;

	int m = l+(r-l)/2;
	seg[p] = build(p*2, l, m) + build(p*2+1, m+1, r);
	seg[p] += llabs(sarea2(v[l], v[m], v[m+1])) + llabs(sarea2(v[l], v[m+1], v[r]));

	return seg[p];
}

int query(int a, int b, int p = 1, int l = 0, int r = n-1){
	if(a > r or b < l) return 0;
	if(a <= l and r <= b) return seg[p];

	int m = l+(r-l)/2;
	int ans = query(a, b, p*2, l, m) + query(a, b, p*2+1, m+1, r);
	if(a <= m and m <= b) 
		ans += llabs(sarea2(v[max(l, a)], v[m], v[min(m+1, b)])) + llabs(sarea2(v[max(l, a)], v[min(m+1, b)], v[min(r, b)]));

	return ans;
}

void solve(){
	int m; cin >> n >> m;
	v = vector<pt>(n); for(auto& x: v) cin >> x;

	int initial_area = build();

	int best = 0;
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b; --a, --b;
		if(a > b) swap(a, b);

		int area = query(a, b);
		best = max(best, min(area, initial_area-area));
	}

	cout << fixed << setprecision(9) << (long double)best/2.0 << endl;
}

int32_t main(){
	int ttt = 1; //cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


