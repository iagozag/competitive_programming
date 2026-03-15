#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7, ROUND = 1e13;
const ld eps = 1e-13;

struct pt{
	int x, y;
	pt(): x(0), y(0) {}
	pt(int _x, int _y): x(_x), y(_y) {}

	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		if (y != p.y) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
};

// Ax + By = C

void solve(){
	int n; cin >> n;
	vector<pair<pt, int>> v;
	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int x = x2-x1, y = y2-y1, g = __gcd(abs(x), abs(y));
		x /= g, y /= g;

		if(y < 0 or(y == 0 and x < 0)) x *= -1, y *= -1;

		int c = x*y1 - y*x1;

		v.emplace_back(pt(x, y), c);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	n = v.size();

	int ans = 0; map<pt, int> mp;
	for(int i = 0; i < n; i++){
		auto [p, C] = v[i];
		ans += mp[pt(-p.y, p.x)];
		mp[p]++;
	}

	cout << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
