#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pi M_PI

typedef long long ll;

const int MAX = 2e6+10, LINF = 0x3f3f3f3f3f3f3f3fll, MOD = 1e9+7;

int fexp(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%MOD;
		b >>= 1, a = a*a%MOD;
	}
	return ans;
}

int fact[MAX];

int comb(int a, int b){
	return fact[a]*fexp(fact[b], MOD-2)%MOD*fexp(fact[a-b], MOD-2)%MOD;
}

void solve(){
	int n; cin >> n;
	if(n&1){ cout << 0 << endl; return; }

	n /= 2;

	cout << comb(2*n, n)*fexp(n+1, MOD-2)%MOD << endl;
}

int32_t main(){
	int ttt = 1; // cin >> ttt;

	fact[0] = 1;
	for(int i = 1; i < MAX; i++) fact[i] = fact[i-1]*i%MOD; 

	while(ttt--) solve();

	exit(0);
}

