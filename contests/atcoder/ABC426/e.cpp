#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;
const double eps = 1e-9;

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld norm(pt v) { // norma do vetor
	return dist(pt(0, 0), v);
}

pt ts, tg, as, ag;
pt vt, va;
ld total_t, total_a;

ld f(ld time){
	ld perc_t = min((ld)1.0, time/total_t);
	ld perc_a = min((ld)1.0, time/total_a);

	pt t = ts+vt*perc_t, a = as+va*perc_a;

	return dist(t, a);
}

void solve(){
	cin >> ts >> tg >> as >> ag;
	total_t = dist(ts, tg);
	total_a = dist(as, ag);

	vt = tg-ts, va = ag-as;

	ld l = 0, r = min(total_t, total_a);
	for(int i = 0; i < 60; i++){
		ld m1 = l+(r-l)/3, m2 = r-(r-l)/3;

		ld f1 = f(m1), f2 = f(m2);
		if(f1 > f2) l = m1;
		else r = m2;
	}

	ld ans = min(f(l), f(r));

	l = min(total_t, total_a), r = max(total_t, total_a);
	for(int i = 0; i < 60; i++){
		ld m1 = l+(r-l)/3, m2 = r-(r-l)/3;

		ld f1 = f(m1), f2 = f(m2);
		if(f1 > f2) l = m1;
		else r = m2;
	}
	ans = min({ans, f(l), f(r)});

	cout << fixed << setprecision(12) << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
