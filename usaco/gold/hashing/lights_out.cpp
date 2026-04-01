#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7, MOD2 = 1e9+9;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p;
	str_hash(vector<int>& s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|

struct pt{
	int x, y;
	pt(int x_ = 0, int y_ = 0): x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if(x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const{
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const{ return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const{ return pt(x-p.x, y-p.y); }
	int operator ^ (const pt p) const{ return x*p.y-y*p.x; }
};

int sarea2(pt p, pt q, pt r){
	return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r){
	return sarea2(p, q, r) > 0;
}

void solve(){
	int n; cin >> n;
	vector<pt> p(n);
	for(auto& pp: p) cin >> pp.x >> pp.y;

	vector<int> v;
	for(int i = 1; i < n; i++){
		v.emplace_back(ccw(p[(i-1+n)%n], p[i], p[(i+1)%n]));
		if(i < n-1) v.emplace_back(abs(p[i].x-p[(i+1)%n].x + p[i].y-p[(i+1)%n].y));
	}

	str_hash<MOD> h1(v); str_hash<MOD2> h2(v);
	map<pair<int, int>, int> mp;
	for(int i = 0; i < (int)v.size(); i++) for(int j = i; j < (int)v.size(); j += 2){
		mp[make_pair(h1(i, j), h2(i, j))]++;
	}

	vector<int> get_l(n), get_r(n);
	for(int i = 1; i < n; i++) get_l[i] = get_l[i-1]+abs(p[i].x-p[i-1].x + p[i].y-p[i-1].y);
	for(int i = n-1; i; i--) get_r[i] = get_r[(i+1)%n]+abs(p[i].x-p[(i+1)%n].x + p[i].y-p[(i+1)%n].y);
	
	int ans = max(get_r[n-1]-get_l[n-1], 0ll);
	for(int i = 1; i < n; i++){
		int best = min(get_l[i], get_r[i]);

		int sum = 0; bool ok = 0;
		for(int j = i+1; j < n; j++){
			sum += abs(p[j].x-p[j-1].x + p[j].y-p[j-1].y);
			if(mp[make_pair(h1((i-1)*2, (j-1)*2), h2((i-1)*2, (j-1)*2))] == 1){
				ans = max(ans, sum+min(get_l[j], get_r[j])-best);
				ok = 1;
				break;
			}
		}

		if(!ok) ans = max(ans, get_r[i]-best);
	}

	cout << ans << endl;
}

int32_t main(){ _
	if (fopen("lightsout.in", "r")) {
		freopen("lightsout.in", "r", stdin);
		freopen("lightsout.out", "w", stdout);
	}
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
