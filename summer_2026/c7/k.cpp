#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 2e5+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 998244353;

int fact[MAX];

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		b >>= 1, a = a*a%MOD;
	}
	return ans;
}

int inv(int x){
	return fexp(x, MOD-2);
}

void solve(){
	int n; cin >> n;
	map<int, int> mp; for(int i = 0; i < n; i++){ int x; cin >> x; mp[x]++; }

	int ans = fact[n];

	auto [a, big] = *mp.rbegin();
	if(big > 1){ cout << ans << endl; return; }
	if(!mp.count(a-1)){ cout << 0 << endl; return; }

	int sec = mp[a-1], rest = n-1-sec;
	for(int i = n; i >= big+sec; i--){
		ans -= fact[i-1]*inv(fact[i-1-sec])%MOD*fact[rest]%MOD;
		ans %= MOD, ans += MOD, ans %= MOD;
	}

	cout << ans << endl;
}

int32_t main(){
	int ttt = 1; cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < MAX; i++) fact[i] = fact[i-1]*i%MOD;

	while(ttt--) solve();

	exit(0);
}
