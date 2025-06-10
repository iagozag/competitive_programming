#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

struct pt {
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

int cross(pt p, pt q, pt r) {
	int c = (q-p)^(r-p);
	if(c > 0) return -1;
	if(c < 0) return 1;
	return 0;
}

void solve(){
	int n; cin >> n;
	vector<pt> v;
	for(int i = 0; i < n; i++){ int x, y; cin >> x >> y; v.emplace_back(x, y); }

	int a, b; cin >> a >> b;
	pt o(a, b);

	int c = cross(o, v[n-1], v[0]);
	for(int i = 0; i < n-1; i++){
		if(cross(o, v[i], v[i+1]) != c){ cout << "N" << endl; return; }
	}
	cout << "S" << endl;
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
