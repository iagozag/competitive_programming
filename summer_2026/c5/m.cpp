#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef long long ll;

const int MAX = 1e5+10, INF = 0x3f3f3f3f, MOD = 1e9+7;
const long double pi = 2.0*acos(0);

struct pt{
	int x, y;
};

void solve(){
	long double m, n, r; cin >> m >> n >> r;

	pt a, b; cin >> a.x >> a.y >> b.x >> b.y;

	long double ans = INF, len = r/n;
	for(int i = 0; i <= a.y; i++){
		int diff1 = a.y-i, diff2 = abs(b.y-i);
		long double cur = (long double)(diff1+diff2)*len;
		
		long double total_r = len*i;
		long double per = pi*(long double)total_r;
		long double pie = per/m, diff = fabs(a.x-b.x);
		cur += pie*diff;

		ans = min(ans, cur);
	}

	cout << fixed << setprecision(9) << ans << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


