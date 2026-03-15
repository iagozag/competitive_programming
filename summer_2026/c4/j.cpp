#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

// Geometria

typedef long double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-6;

#define sq(x) ((x)*(x))

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

// PONTO & VETOR

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

void solve(){
	int n; cin >> n;
	vector<pair<int, ld>> qu(n); int type = 0;
	for(int i = 0; i < n; i++){
		string s, x; cin >> s >> x;
		if(s == "fd") qu[i].first = 0;
		else if(s == "bk") qu[i].first = 1;
		else if(s == "lt") qu[i].first = 2;
		else qu[i].first = 3;

		if(x == "?"){
			qu[i].second = -1;
			if(qu[i].first >= 2) type = 1;
		}
		else qu[i].second = stoll(x);
	}

	pt dir(1, 0), cur(0, 0);
	if(type == 0){
		for(auto [a, b]: qu) if(b != -1){
			if(a == 0) cur = cur+(dir*b);
			else if(a == 1) cur = cur-(dir*b);
			else if(a == 2) dir = rotate(dir, pi*b/180.0);
			else dir = rotate(dir, -pi*b/180.0);
		}

		cout << (int)round(dist(pt(0, 0), cur)) << endl;
	}
	else{
		for(int i = 0; i < 360; i++){
			dir = pt(1, 0), cur = pt(0, 0);
			for(auto [a, b]: qu){
				if(b == -1) b = (ld)i;

				if(a == 0) cur = cur+(dir*b);
				else if(a == 1) cur = cur-(dir*b);
				else if(a == 2) dir = rotate(dir, pi*b/180.0);
				else dir = rotate(dir, -pi*b/180.0);
			}
			
			if(cur == pt(0, 0)){ cout << i << endl; return; }
		}
	}
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
