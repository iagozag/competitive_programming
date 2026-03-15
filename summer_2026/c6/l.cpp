#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	long double n, m, k; cin >> n >> m >> k; long double prev = k;
	long double ans = 0;
	if(m >= k-1) ans += (k-1)/k, m -= (k-1), k = 1;
	else ans += m/k, k -= m, m = 0;

	ans += (m/(n+m))/prev;

	cout << fixed << setprecision(12) << ans << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


