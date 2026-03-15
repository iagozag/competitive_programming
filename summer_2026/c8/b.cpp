#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 1e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

void solve(){
	int c, r, s; cin >> c >> r >> s;
	int need = (r+s-1)/s;
	int diff = need*s-r;
	int ma = (c-diff+s-1)/s;

	c -= r*(s-1);

	cout << ma << ' ' << max(0ll, (c+s-1)/s) << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	while(ttt--) solve();

	exit(0);
}


