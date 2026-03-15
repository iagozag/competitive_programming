#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int LINF = 0x3f3f3f3f3f3f3f3fll;

struct pt{
	 int x, y;
	 pt(int x_ = 0, int y_ = 0): x(x_), y(y_) {}
	 bool operator < (const pt p) const{
		if(x != p.x) return x < p.x;
		return y < p.y;
	 }

	 bool operator == (const pt p) const{
		return x == p.x and y == p.y;
	 }

	 pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	 pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	 int operator ^ (const pt p) const { return x*p.y - y*p.x; }
};

int sarea2(pt p, pt q, pt r){ return (q-p)^(r-q); }
bool ccw(pt p, pt q, pt r){ return sarea2(p, q, r) > 0; }

vector<pt> convex_hull(vector<pt> v){
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if(v.size() <= 1) return v;
	vector<pt> l, u;
	for(int i = 0; i < (int)v.size(); i++){
		while(l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i])) 
			l.pop_back();
		l.push_back(v[i]);
	}

	for(int i = v.size()-1; i >= 0; i--){
		while(u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i])) 
			u.pop_back();
		u.push_back(v[i]);
	}

	l.pop_back(), u.pop_back();
	for(pt i: u) l.push_back(i);
	return l;
}

int n;
void solve(){
	vector<pt> v(n);
	for(int i = 0; i < n; i++){ int a, b; cin >> a >> b; v[i] = pt(a, b); }

	vector<pt> cv = convex_hull(v);

	cout << cv.size() << endl;
	for(pt p: cv) cout << p.x << ' ' << p.y << endl;
}

int32_t main(){
	while(cin >> n and n) solve();

	exit(0);
}

