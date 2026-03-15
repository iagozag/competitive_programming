#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int a, b, x, y; cin >> a >> b >> x >> y; int g = __gcd(x, y);
	x /= g, y /= g;

	int l = 0, r = 2e18, ans = 0;
	while(l <= r){
		int m = l+(r-l)/2;

		if(log10(x)+log10(m) > 18 or log10(y)+log10(m) > 18){ r = m-1; continue; }

		if(x*m <= a and y*m <= b) ans = m, l = m+1;
		else r = m-1;
	}

	cout << ans << endl;
}

int32_t main(){ _
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


