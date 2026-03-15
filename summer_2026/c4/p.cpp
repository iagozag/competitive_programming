#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
	int operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	int operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
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

int inpol(vector<pt>& v, pt p) { // O(n)
	int qt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (p == v[i]) return 2;
		int j = (i+1)%v.size();
		if (p.y == v[i].y and p.y == v[j].y) {
			if ((v[i]-p)*(v[j]-p) <= 0) return 2;
			continue;
		}
		bool baixo = v[i].y < p.y;
		if (baixo == (v[j].y < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (!t) return 2;
		if (baixo == (t > 0)) qt += baixo ? 1 : -1;
	}
	return qt != 0;
}

int c, r, o;
void solve(){
	vector<pt> cops(c), robbers(r);
	for(int i = 0; i < c; i++) cin >> cops[i];
	for(int i = 0; i < r; i++) cin >> robbers[i];
	
	vector<pt> cvcops = convex_hull(cops);
	vector<pt> cvrobbers = convex_hull(robbers);

	for(int i = 0; i < o; i++){
		pt city; cin >> city;

		cout << "     Citizen at (" << city.x << "," << city.y << ") is ";
			
		if(c > 2 and inpol(cvcops, city) != 0) cout << "safe." << endl;
		else if(r > 2 and inpol(cvrobbers, city) != 0) cout << "robbed." << endl;
		else cout << "neither." << endl;
	}
}

int32_t main(){ _
	int t = 1;
	while(cin >> c >> r >> o and (c or r or o)){
		cout << "Data set " << t++ << ":" << endl;
		solve();
		cout << endl;
	}

	exit(0);
}

