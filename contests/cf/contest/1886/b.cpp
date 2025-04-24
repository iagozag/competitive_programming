#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

long double dist(long double a, long double b, long double c, long double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

void solve(){
	long double px, py, ax, ay, bx, by; cin >> px >> py >> ax >> ay >> bx >> by;

	long double l = 0, r = 3e6, ans = r, eps = 1e-12;
	while(r-l > eps){
		long double m = (r+l)/2.0;

		bool can = false;
		if(dist(0.0, 0.0, ax, ay) <= m){
			if(dist(ax, ay, px, py) <= m) can = 1;
			else if(dist(ax, ay, bx, by) <= 2.0*m and dist(bx, by, px, py) <= m) can = 1;
		} else if(dist(0.0, 0.0, bx, by) <= m){
			if(dist(bx, by, px, py) <= m) can = 1;
			else if(dist(ax, ay, bx, by) <= 2.0*m and dist(ax, ay, px, py) <= m) can = 1;
		}

		if(can) r = m, ans = m;
		else l = m;
	}

	cout << fixed << setprecision(12) << ans << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
